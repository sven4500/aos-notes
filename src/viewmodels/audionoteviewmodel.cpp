#include <QDebug>

#include "audionoteviewmodel.h"
#include "models/audionotemodel.h"

namespace ViewModels {

AudioNoteViewModel::AudioNoteViewModel(Models::AudioNoteModel* model, QObject *parent)
    : NoteViewModel(parent)
    , m_model(model)
{

}

void AudioNoteViewModel::insertNote()
{
    qDebug();
}

void AudioNoteViewModel::removeNote()
{
    qDebug() << m_id;

    if (m_id != 0) {

    } else {
        qDebug() << "can not remove temporary note";
    }
}

const QString &AudioNoteViewModel::outputLocation() const
{
    return m_model->TemporaryFilePath;
}

}
