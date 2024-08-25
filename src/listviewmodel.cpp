#include "listviewmodel.h"

ListViewModel::ListViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
    connect(this, &QAbstractListModel::rowsInserted,
            this, &ListViewModel::rowCountChanged);
    connect(this, &QAbstractListModel::rowsRemoved,
            this, &ListViewModel::rowCountChanged);
}

int ListViewModel::rowCount(const QModelIndex &parent) const
{
    return 0;
}

QVariant ListViewModel::data(const QModelIndex &index, int role) const
{
    return {};
}

QHash<int, QByteArray> ListViewModel::roleNames() const
{
    return {};
}
