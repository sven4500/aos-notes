#include <QDateTime>
#include <QDebug>

#include "models/textnotemodel.h"
#include "textnoteviewmodel.h"

namespace ViewModels {

TextNoteViewModel::TextNoteViewModel(Models::TextNoteModel* model, QObject *parent)
    : NoteViewModel(parent)
    , m_model(model)
{
    connect(this, &TextNoteViewModel::idChanged,
            this, &TextNoteViewModel::onIdChanged);
}

void TextNoteViewModel::insertNote()
{
    qDebug() << m_id << m_title << m_body;

    if (m_id != 0) {
        qDebug() << "update text note";
        m_model->update(m_id, m_title, m_body);
    }
    else {
        if (!m_title.isEmpty() || !m_body.isEmpty()) {
            qDebug() << "create new text note";
            m_model->insert(!m_title.isEmpty() ? m_title : defaultTitle(), m_body);
        } else {
            qDebug() << "nothing to save";
        }
    }
}

void TextNoteViewModel::removeNote()
{
    qDebug() << m_id << m_title << m_body;

    if (m_id != 0) {
        m_model->remove(m_id);
    } else {
        qDebug() << "can not remove temporary note";
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

void TextNoteViewModel::onIdChanged()
{
    if (id() != 0) {
        std::optional<DTO::TextNote> const textNote = m_model->find(id());
        if (!textNote) {
            qDebug() << "no such text note with id" << id();
            return;
        }
        setTitle(textNote->title);
        setBody(textNote->body);
    } else {
        setTitle({});
        setBody({});
    }
}

}
