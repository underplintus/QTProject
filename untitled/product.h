#ifndef PRODUCT_H
#define PRODUCT_H


#include <QAbstractTableModel>

class TableModel: public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TableModel(QObject *parent = nullptr);
    ~TableModel();
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QList<QString> operator[](int i);

    void addRow(const QList<QString>& list);
    void deleteRow(int index);

private:
    QList<QList<QString>> dataTable;
    QString header;
};

#endif // Product_H
