#include <QDebug>

#include "sketchnoteviewmodel.h"

namespace ViewModels {

SketchNoteViewModel::SketchNoteViewModel(Models::SketchNoteModel *model, QObject *parent)
    : NoteViewModel(parent)
    , m_model(model)
{

}

void SketchNoteViewModel::insertNote()
{
    qDebug();
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

}
