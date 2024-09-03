#include <QDebug>

#include "textnoteviewmodel.h"

namespace ViewModels {

TextNoteViewModel::TextNoteViewModel(QObject *parent)
    : QObject(parent)
{

}

void TextNoteViewModel::saveNote()
{
    qDebug() << "save text note clicked" << m_id << m_title << m_body;
}

int TextNoteViewModel::id() const
{
    return m_id;
}

void TextNoteViewModel::setId(int newId)
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

}
