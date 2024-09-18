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
    qDebug() << m_id << m_title;

    if (m_id != 0) {
        qDebug() << "audio note update not supported";
    }
    else {
        // TODO: or recording duration not null
        if (!m_title.isEmpty()) {
            qDebug() << "create new audio note";
            m_model->insert(!m_title.isEmpty() ? m_title : defaultTitle());
        } else {
            qDebug() << "nothing to save";
        }
    }
}

void AudioNoteViewModel::removeNote()
{
    qDebug() << m_id << m_title;

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
