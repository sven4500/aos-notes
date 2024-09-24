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
    Q_PROPERTY(bool empty READ empty WRITE setEmpty)

    explicit SketchNoteViewModel(Models::SketchNoteModel *model, QObject *parent = nullptr);

    virtual void insertNote();
    virtual void removeNote();

    QSharedPointer<QQuickItemGrabResult> grab() const;
    void setGrab(QSharedPointer<QQuickItemGrabResult> newImage);

    bool empty() const;
    void setEmpty(bool newEmpty);

private slots:
    void onGrabReady();

private:
    QImage m_image;
    QSharedPointer<QQuickItemGrabResult> m_grab;
    Models::SketchNoteModel* m_model = nullptr;
    bool m_empty = true;

};

}

#endif // SKETCHVIEWMODEL_H
