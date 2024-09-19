#include <QDebug>

#include "audionoteviewmodel.h"
#include "models/audionotemodel.h"

namespace ViewModels {

AudioNoteViewModel::AudioNoteViewModel(Models::AudioNoteModel* model, QObject *parent)
    : NoteViewModel(parent)
    , m_model(model)
{
    connect(this, &AudioNoteViewModel::idChanged,
            this, &AudioNoteViewModel::onIdChanged);
}

void AudioNoteViewModel::insertNote()
{
    qDebug() << m_id << m_title;

    if (m_id != 0) {
        qDebug() << "update audio note";
        m_model->update(m_id, m_title);
    }
    else {
        // TODO: recording duration not null
        if (true) {
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
        m_model->remove(m_id);
    } else {
        qDebug() << "can not remove temporary note";
    }
}

QString AudioNoteViewModel::parseTime(int milliseconds)
{
    auto const seconds = (milliseconds / 1000) % 60;
    auto const minutes = (milliseconds / 1000 / 60) % 60;
    auto const hours = qMin(milliseconds / 1000 / 60 / 60, 99);

    return QString("%1:%2:%3")
            .arg(hours, 2, 10, QChar('0'))
            .arg(minutes, 2, 10, QChar('0'))
            .arg(seconds, 2, 10, QChar('0'));
}

const QString &AudioNoteViewModel::outputLocation() const
{
    return m_model->TemporaryFilePath;
}

void AudioNoteViewModel::onIdChanged()
{
    if (id() != 0) {
        std::optional<DTO::AudioNote> const audioNote = m_model->find(id());
        if (!audioNote) {
            qDebug() << "no such audio note with id" << id();
            return;
        }
        setTitle(audioNote->title);
        setMediaPath(audioNote->filePath);
    } else {
        setTitle({});
    }
}

const QString &AudioNoteViewModel::mediaPath() const
{
    return m_mediaPath;
}

void AudioNoteViewModel::setMediaPath(const QString &newMediaPath)
{
    if (m_mediaPath == newMediaPath)
        return;
    m_mediaPath = newMediaPath;
    emit mediaPathChanged();
}

}
