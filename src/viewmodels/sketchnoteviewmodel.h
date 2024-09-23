#ifndef SKETCHVIEWMODEL_H
#define SKETCHVIEWMODEL_H

#include <QObject>

#include "noteviewmodel.h"

namespace Models {
class SketchNoteModel;
}

namespace ViewModels {

class SketchNoteViewModel: public NoteViewModel
{
    Q_OBJECT

public:
    explicit SketchNoteViewModel(Models::SketchNoteModel *model, QObject *parent = nullptr);

    virtual void insertNote();
    virtual void removeNote();

private:
    Models::SketchNoteModel* m_model = nullptr;

};

}

#endif // SKETCHVIEWMODEL_H
