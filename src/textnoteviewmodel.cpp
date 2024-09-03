#include <QDebug>

#include "textnoteviewmodel.h"

namespace ViewModels {

TextNoteViewModel::TextNoteViewModel(QObject *parent)
    : AbstractNoteViewModel(parent)
{

}

void TextNoteViewModel::saveNote()
{
    qDebug() << "save abstract note clicked" << m_id << m_title << m_body;
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
