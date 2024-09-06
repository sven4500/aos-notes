#include "databasemodel.h"
#include "textnotemodel.h"

namespace Models {

TextNoteModel::TextNoteModel(QObject *parent)
    : QObject(parent)
    , m_databaseModel(new DatabaseModel(this))
{

}

void TextNoteModel::create(QString title, QString body)
{
    Q_UNUSED(body);
    m_databaseModel->create(Models::DatabaseModel::TextNote, title, "mediapath");
}

void TextNoteModel::update(const DTO::TextNote &note)
{

}

void TextNoteModel::update(qint64 id, QString title, QString body)
{

}

DTO::TextNote TextNoteModel::find(qint64 id)
{
    return {};
}

void TextNoteModel::erase(qint64 id)
{

}

}
