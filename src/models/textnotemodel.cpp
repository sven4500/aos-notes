#include <QDebug>
#include <QStandardPaths>
#include <QTextStream>
#include <QUuid>

#include "dao/databasedao.h"
#include "dto/textnote.h"
#include "textnotemodel.h"

namespace Models {

QDir const TextNoteModel::WorkingDir =
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) +
        QDir::separator() + "notes" + QDir::separator() + "text";

TextNoteModel::TextNoteModel(QObject *parent)
    : QObject(parent)
    , m_databaseDao(new DAO::DatabaseDAO(this))
{
    qsrand(time(nullptr));
    QDir().mkdir(WorkingDir.path());
}

void TextNoteModel::insert(QString title, QString body)
{
    auto const uuid = QUuid::createUuid();
    QString const filePath = WorkingDir.filePath(uuid.toString() + ".txt");
    QFile file(filePath);
    if(!file.open(QFile::WriteOnly | QFile::Truncate)) {
        qDebug() << "failed to open file" << filePath;
        return;
    }
    QTextStream textStream(&file);
    textStream << body;
    file.close();

    m_databaseDao->insert(DTO::DatabaseEntry::TextNote, title, filePath);
}

void TextNoteModel::update(qint64 id, QString title, QString body)
{

}

std::optional<DTO::TextNote> TextNoteModel::find(qint64 id) const
{
    auto const databaseEntry = m_databaseDao->find(id);
    if (!databaseEntry) {
        qDebug() << "no such text note with id" << id;
        return {};
    }

    return DTO::TextNote {id, databaseEntry->title, ""};
}

void TextNoteModel::remove(qint64 id)
{
    auto const databaseEntry = m_databaseDao->find(id);
    if (!databaseEntry) {
        qDebug() << "no such text note found with id" << id;
        return;
    }

    m_databaseDao->remove(id);

    QFile file(databaseEntry->media);
    file.remove();
}

}
