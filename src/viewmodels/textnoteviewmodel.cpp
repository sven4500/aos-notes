#include <QDebug>

#include "models/textnotemodel.h"
#include "textnoteviewmodel.h"

namespace ViewModels {

TextNoteViewModel::TextNoteViewModel(Models::TextNoteModel* model, QObject *parent)
    : QObject(parent)
    , m_model(model)
{

}

void TextNoteViewModel::saveNote()
{
    qDebug() << "save text note" << m_id << m_title << m_body;

    if (m_id == 0) {
        if (!m_title.isEmpty() || !m_body.isEmpty()) {
            qDebug() << "create new text note";
            m_model->create(m_title, m_body);
        } else {
            qDebug() << "nothing to save";
        }
    }
    else {
        qDebug() << "update text note";
        m_model->update(m_id, m_title, m_body);
    }
}

const QString &TextNoteViewModel::body() const
{
    return m_body;
}

void TextNoteViewModel::setBody(const QString &newBody)
{
    if (m_body == newBody)
        return;
    m_body = newBody;
    emit bodyChanged();
}

qint64 TextNoteViewModel::id() const
{
    return m_id;
}

void TextNoteViewModel::setId(qint64 newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    emit idChanged();
}

const QString &TextNoteViewModel::title() const
{
    return m_title;
}

void TextNoteViewModel::setTitle(const QString &newTitle)
{
    if (m_title == newTitle)
        return;
    m_title = newTitle;
    emit titleChanged();
}

}
