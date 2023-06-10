#include "tablemodel.h"
#include <QFile>




TableModel::~TableModel()
{
    QFile inputFile("/Users/vladimirkalinovskii/Desktop/project/SPEC/data2.csv");
    inputFile.open(QFile::WriteOnly | QFile::Text);
    QTextStream inputStream(&inputFile);

    for (const QString& i: header.split(',')) // доделать, чтобы в последнем хедере не добавлялась запятая
    {
        inputStream << i << ',';
    }

    inputStream << '\n';
    for (const QList<QString>& i: dataTable)
    {
        for (const QString& j: i)
            inputStream << j << ',';

        inputStream << '\n';
    }
    inputFile.close();

}


TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    QFile inputFile("/Users/vladimirkalinovskii/Desktop/project/SPEC/data.csv");
    inputFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream inputStream(&inputFile);

    header = inputStream.readLine().replace("\"","");
    qDebug()<<header;

    while(!inputStream.atEnd())
    {
        QString line = inputStream.readLine().replace("\"","");

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

}

bool TableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}


bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value)
    {
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

void TableModel::addRow(const QList<QString>& list)
{
    beginInsertRows(QModelIndex(), 0, 1);
    dataTable.insert(0, list);
    endInsertRows();
}

void TableModel::deleteRow(int index)
{
    beginRemoveRows(QModelIndex(), index, index + 1);
    dataTable.removeAt(index);
    endRemoveRows();

}

QList<QString> TableModel::operator[](int i)
{
    return dataTable[i];
}

QList<QString> TableModel::tranList()
{
    QList<QString> transatctions;
    for (const QList<QString>&  line: dataTable)
        transatctions.append(line[1]);

    return transatctions;
}

QList<QString> TableModel::producView()
{
    QList<QString> products;
    for (const QList<QString>&  line: dataTable)
        products.append(line[2]);

    return products;
}
