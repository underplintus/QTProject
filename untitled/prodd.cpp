#include "prodd.h"
#include "ui_prodd.h"




TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    QFile inputFile("/Users/vladimirkalinovskii/Desktop/project/SPEC/data.csv");
    inputFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream inputStream(&inputFile);

    header = inputStream.readLine();
    qDebug()<<header;

    while(!inputStream.atEnd())
    {
        QString line = inputStream.readLine();

        QList<QString> dataRow;
        for (QString& item : line.split(",")) {
            dataRow.append(item);
        }
        dataTable.append(dataRow);
    }
    inputFile.close();
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return dataTable.count();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return dataTable[0].count();
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole || role == Qt::EditRole)
        return dataTable[index.row()][index.column()];
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    //    return QVariant();
    qDebug()<<section;
    if ((role == Qt::DisplayRole) && orientation == (Qt::Horizontal))
    {
        return header.split(',')[section];
    }
    return QVariant();
    //     FIXME: Implement me!

}

bool TableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}


bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        dataTable[index.row()][index.column()] = value.toString();
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;

}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable; // FIXME: Implement me!
}
