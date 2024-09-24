#include <QDebug>

#include "models/sketchnotemodel.h"
#include "sketchnoteviewmodel.h"

namespace ViewModels {

SketchNoteViewModel::SketchNoteViewModel(Models::SketchNoteModel *model, QObject *parent)
    : NoteViewModel(parent)
    , m_model(model)
{
    connect(this, &SketchNoteViewModel::idChanged,
            this, &SketchNoteViewModel::onIdChanged);
}

void SketchNoteViewModel::insertNote()
{
    qDebug() << m_id << m_title;

    if (m_id != 0) {
        qDebug() << "update sketch note";
        m_model->update(m_id, m_title, m_image);
    }
    else {
        if (!m_title.isEmpty() || !m_empty) {
            qDebug() << "create new sketch note";
            m_model->insert(m_title, m_image);
        }
        else {
            qDebug() << "nothing to save";
        }
    }
}

void SketchNoteViewModel::removeNote()
{
    qDebug() << m_id << m_title;

    if (m_id != 0) {
        m_model->remove(m_id);
    } else {
        qDebug() << "can not remove temporary note";
    }
}

QSharedPointer<QQuickItemGrabResult> SketchNoteViewModel::grab() const
{
    return m_grab;
}

void SketchNoteViewModel::setGrab(QSharedPointer<QQuickItemGrabResult> newGrab)
{
    m_grab = newGrab;
    connect(m_grab.data(), &QQuickItemGrabResult::ready,
            this, &SketchNoteViewModel::onGrabReady);
}

void SketchNoteViewModel::onGrabReady()
{
    qDebug();
    setImage(m_grab->image());
}

void SketchNoteViewModel::onIdChanged()
{
    if (id() != 0) {
        std::optional<DTO::SketchNote> const sketchNote = m_model->find(id());
        if (!sketchNote) {
            qDebug() << "no such sketch note with id" << id();
            return;
        }
        qDebug() << "load sketch DTO with id" << sketchNote->id;
        setTitle(sketchNote->title);
        setEmpty(false);
        setImage(sketchNote->image);
    } else {
        setTitle({});
        setEmpty(true);
        setImage({});
    }
}

bool SketchNoteViewModel::empty() const
{
    return m_empty;
}

void SketchNoteViewModel::setEmpty(bool newEmpty)
{
    qDebug() << newEmpty;
    m_empty = newEmpty;
}

const QImage &SketchNoteViewModel::image() const
{
    return m_image;
}

void SketchNoteViewModel::setImage(const QImage &newImage)
{
    if (m_image == newImage)
        return;
    m_image = newImage;
    emit imageChanged();
}

}
