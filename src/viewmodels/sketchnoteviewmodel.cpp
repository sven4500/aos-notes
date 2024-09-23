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

}
