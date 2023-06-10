#include "proxymodel.h"

ProxyModel::ProxyModel(QObject* parent): QSortFilterProxyModel(parent), _customerID("")
{

}


QVariant ProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return sourceModel()->headerData(section, orientation, role);
}

bool ProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex customerIDIndex = sourceModel()->index(source_row, 6, source_parent);
    bool isContains = (((sourceModel()->data(customerIDIndex)).toString()).contains(_customerID, Qt::CaseInsensitive));
    if(isContains)
        return true;
    return false;
}



void ProxyModel::setCustomerID(const QString& string)
{
    _customerID = string;
    invalidateFilter();
}


