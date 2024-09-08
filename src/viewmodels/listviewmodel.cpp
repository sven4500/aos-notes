#include <QDebug>

#include "listviewmodel.h"
#include "../models/databasemodel.h"

ListViewModel::ListViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
    srand(time(nullptr));

    // INFO: https://stackoverflow.com/questions/51728264/model-rowcount-wont-bind-to-items-property
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
    //auto const i = index.row();

    switch(role) {
    case NoteType:
        return Models::DatabaseModel::TextNote;

    default:
        qDebug() << "no such role exist" << role;
        return {};
    }
}

QHash<int, QByteArray> ListViewModel::roleNames() const
{
    return {
        {DateTimeRole, "dateTime"},
        {NoteType, "type"}
    };
}
