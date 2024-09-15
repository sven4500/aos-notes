#include <QDebug>

#include "dao/databasedao.h"
#include "listviewmodel.h"

namespace ViewModels {

ListViewModel::ListViewModel(DAO::DatabaseDAO* databaseDAO, QObject *parent)
    : QAbstractListModel(parent)
    , m_databaseDAO(databaseDAO)
{
    srand(time(nullptr));

    m_notes = m_databaseDAO->list();
    connect(m_databaseDAO, &DAO::DatabaseDAO::inserted,
            this, &ListViewModel::onNoteInserted);
    connect(m_databaseDAO, &DAO::DatabaseDAO::removed,
            this, &ListViewModel::onNoteRemoved);
    connect(m_databaseDAO, &DAO::DatabaseDAO::updated,
            this, &ListViewModel::onNoteUpdated);

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

void ListViewModel::onNoteInserted(qint64 id)
{
    qDebug() << id;

    auto const& entry = m_databaseDAO->find(id);
    if (!entry) {
        qDebug() << "no note found with id" << id;
        return;
    }

    int const i = 0;

    beginInsertRows(QModelIndex(), i, i);
    m_notes.insert(i, *entry);
    endInsertRows();

    qDebug() << "note inserted at row" << i;
}

void ListViewModel::onNoteRemoved(qint64 id)
{
    qDebug() << id;

    auto const& note = std::find_if(m_notes.begin(), m_notes.end(), [&id](auto const& entry){ return entry.id == id; });
    if (note == m_notes.end()) {
        qDebug() << "no note found with id" << id;
        return;
    }

    int const i = std::distance(m_notes.begin(), note);

    if (i >= m_notes.size()) {
        qDebug() << "out of range index" << i;
        return;
    }

    beginRemoveRows(QModelIndex(), i, i);
    m_notes.removeAt(i);
    endRemoveRows();

    qDebug() << "note removed at row" << i;
}

void ListViewModel::onNoteUpdated(qint64 id)
{
    qDebug() << id;

    auto const& entry = m_databaseDAO->find(id);
    if (!entry) {
        qDebug() << "no note found with id" << id;
        return;
    }

    auto const& note = std::find_if(m_notes.begin(), m_notes.end(), [&id](auto const& entry){ return entry.id == id; });
    if (note == m_notes.end()) {
        qDebug() << "no note found with id" << id;
        return;
    }

    int const i = std::distance(m_notes.begin(), note);

    note->title = entry->title;
    note->modifiedAt = entry->modifiedAt;

    // INFO: https://stackoverflow.com/questions/43494905/how-to-update-qabstractitemmodel-view-when-a-data-is-updated
    emit dataChanged(createIndex(i, 0), createIndex(i, 0), {TitleRole, ModifiedAtRole});

    qDebug() << "note updated at row" << i << note->id << note->title << note->modifiedAt;
}

}
