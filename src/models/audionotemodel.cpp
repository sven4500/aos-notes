#include <QStandardPaths>

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

}
