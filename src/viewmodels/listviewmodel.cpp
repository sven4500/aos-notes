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

bool ListViewModel::removeRows(int row, int count, const QModelIndex &parent)
{
    qDebug() << row << count;

    if (row >= m_notes.size()) {
        qDebug() << "row out of bounds" << m_notes.size();
        return false;
    }

    if (count <= 0) {
        qDebug() << "nothing to remove" << count;
        return false;
    }

    if (row + count > m_notes.size()) {
        count = m_notes.size() - row;
        qDebug() << "too many rows to remove, new row count" << count;
    }

    beginRemoveRows(parent, row, row + count - 1);
    for (auto i = 0; i < count; ++i) {
        auto const note = m_notes.takeAt(row);
        m_databaseDAO->remove(note.id);
    }
    endRemoveRows();

    return true;
}
