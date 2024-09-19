#include <QDebug>
#include <QFile>
#include <QStandardPaths>
#include <QUuid>

#include "audionotemodel.h"
#include "dao/databasedao.h"

namespace Models {

QDir const AudioNoteModel::WorkingDir =
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) +
        QDir::separator() + "notes" + QDir::separator() + "audio";
QString const AudioNoteModel::TemporaryFilePath =
        WorkingDir.filePath("temp.wav");

AudioNoteModel::AudioNoteModel(DAO::DatabaseDAO* databaseDAO, QObject *parent)
    : QObject(parent)
    , m_databaseDAO(databaseDAO)
{
    qsrand(time(nullptr));
    QDir().mkdir(WorkingDir.path());
}

std::optional<DTO::AudioNote> AudioNoteModel::find(qint64 id) const
{
    qDebug() << id;

    auto const databaseEntry = m_databaseDAO->find(id);
    if (!databaseEntry) {
        qDebug() << "no such audio note found with id" << id;
        return {};
    }

    return DTO::AudioNote {id, databaseEntry->title, databaseEntry->media};
}

void AudioNoteModel::insert(QString title)
{
    qDebug() << title;

    auto const uuid = QUuid::createUuid();
    QString const filePath = WorkingDir.filePath(uuid.toString().remove('{').remove('}') + ".wav");

    if(!QFile::rename(TemporaryFilePath, filePath)) {
        qDebug() << "failed to rename temporary audio file";
        return;
    }

    m_databaseDAO->insert(DTO::DatabaseEntry::AudioNote, title, filePath);
}

void AudioNoteModel::remove(qint64 id)
{
    auto const databaseEntry = m_databaseDAO->find(id);
    if (!databaseEntry) {
        qDebug() << "no such audio note found with id" << id;
        return;
    }

    m_databaseDAO->remove(id);

    qDebug() << "remove audio file" << databaseEntry->media;
    QFile file(databaseEntry->media);
    file.remove();
}

void AudioNoteModel::update(qint64 id, QString title)
{
    qDebug() << id << title;

    auto const databaseEntry = m_databaseDAO->find(id);
    if (!databaseEntry) {
        qDebug() << "no such text note with id" << id;
        return;
    }

    m_databaseDAO->update(id, title);
}

}
