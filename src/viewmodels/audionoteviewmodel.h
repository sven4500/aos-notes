#ifndef AUDIONOTEVIEWMODEL_H
#define AUDIONOTEVIEWMODEL_H

#include <QObject>

#include "noteviewmodel.h"

namespace Models {
class AudioNoteModel;
}

namespace ViewModels {

class AudioNoteViewModel: public NoteViewModel
{
    Q_OBJECT

public:
    Q_PROPERTY(QString outputLocation READ outputLocation CONSTANT)

    explicit AudioNoteViewModel(Models::AudioNoteModel* model, QObject *parent = nullptr);

    Q_INVOKABLE virtual void insertNote();
    Q_INVOKABLE virtual void removeNote();

    const QString &outputLocation() const;

private:
    void onIdChanged();

    Models::AudioNoteModel* m_model = nullptr;

};

}

#endif // AUDIONOTEVIEWMODEL_H
