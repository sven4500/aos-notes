#include <QDebug>
#include <QStandardPaths>
#include <QUuid>

#include "dao/databasedao.h"
#include "sketchnotemodel.h"

namespace Models {

QDir const SketchNoteModel::WorkingDir =
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) +
        QDir::separator() + "notes" + QDir::separator() + "sketch";

SketchNoteModel::SketchNoteModel(DAO::DatabaseDAO* databaseDAO, QObject *parent)
    : QObject(parent)
    , m_databaseDAO(databaseDAO)
{
    qsrand(time(nullptr));
    QDir().mkdir(WorkingDir.path());
}

void SketchNoteModel::insert(QString title, QImage image)
{
    qDebug() << title;

    auto const uuid = QUuid::createUuid();
    QString const filePath = WorkingDir.filePath(uuid.toString().remove('{').remove('}') + ".png");

    image.save(filePath);

    m_databaseDAO->insert(DTO::DatabaseEntry::SketchNote, title, filePath);
}

void SketchNoteModel::update(qint64 id, QString title, QImage image)
{
    qDebug() << id << title << image;
}

}
