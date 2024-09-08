#include <QDebug>

#include "dao/databasedao.h"
#include "listviewmodel.h"

ListViewModel::ListViewModel(QObject *parent)
    : QAbstractListModel(parent)
    , m_databaseDAO(new DAO::DatabaseDAO(this))
{
    srand(time(nullptr));

    m_notes = m_databaseDAO->list();
    qDebug() << "notes loaded" << m_notes.size();

    // INFO: https://stackoverflow.com/questions/51728264/model-rowcount-wont-bind-to-items-property
    connect(this, &QAbstractListModel::rowsInserted,
            this, &ListViewModel::rowCountChanged);
    connect(this, &QAbstractListModel::rowsRemoved,
            this, &ListViewModel::rowCountChanged);
}

int ListViewModel::rowCount(const QModelIndex &parent) const
{
    return m_notes.count();
}

QVariant ListViewModel::data(const QModelIndex &index, int role) const
{
    auto const i = index.row();
    if (i < 0 || i >= m_notes.count()) {
        qDebug() << "note index out of bounds";
        return {};
    }

    auto const& note = m_notes.at(i);

    switch(role) {
    case IdRole:
        return note.id;

    case NoteTypeRole:
        return note.type;

    case TitleRole:
        return note.title;

    case MediaRole:
        return note.media;

    case CreatedAtRole:
        return note.createdAt;

    case ModifiedAtRole:
        return note.modifiedAt;

    default:
        qDebug() << "no such role exist" << role;
        return {};
    }
}

QHash<int, QByteArray> ListViewModel::roleNames() const
{
    return {
        {IdRole, "id"},
        {NoteTypeRole, "type"},
        {TitleRole, "title"},
        {MediaRole, "media"},
        {CreatedAtRole, "createdAt"},
        {ModifiedAtRole, "modifiedAt"}
    };
}
