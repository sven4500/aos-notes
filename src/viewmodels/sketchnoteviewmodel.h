#ifndef SKETCHVIEWMODEL_H
#define SKETCHVIEWMODEL_H

#include <QImage>
#include <QObject>
#include <QQuickItemGrabResult>
#include <QSharedPointer>

#include "noteviewmodel.h"

namespace Models {
class SketchNoteModel;
}

namespace ViewModels {

class SketchNoteViewModel: public NoteViewModel
{
    Q_OBJECT

public:
    Q_PROPERTY(QSharedPointer<QQuickItemGrabResult> grab READ grab WRITE setGrab)

    explicit SketchNoteViewModel(Models::SketchNoteModel *model, QObject *parent = nullptr);

    virtual void insertNote();
    virtual void removeNote();

    QSharedPointer<QQuickItemGrabResult> grab() const;
    void setGrab(QSharedPointer<QQuickItemGrabResult> newImage);

private slots:
    void onGrabReady();

private:
    QImage m_image;
    QSharedPointer<QQuickItemGrabResult> m_grab;
    Models::SketchNoteModel* m_model = nullptr;

};

}

#endif // SKETCHVIEWMODEL_H
