#include <QDebug>

#include "models/sketchnotemodel.h"
#include "sketchnoteviewmodel.h"

namespace ViewModels {

SketchNoteViewModel::SketchNoteViewModel(Models::SketchNoteModel *model, QObject *parent)
    : NoteViewModel(parent)
    , m_model(model)
{

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
    qDebug();
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
    m_image = m_grab->image();
    //m_image.save("/home/defaultuser/Documents/image.png");
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

}
