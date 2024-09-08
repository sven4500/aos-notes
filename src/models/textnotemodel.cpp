#include <QDebug>
#include <QStandardPaths>
#include <QTextStream>
#include <QUuid>

#include "dao/databasedao.h"
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

void TextNoteModel::create(QString title, QString body)
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

    m_databaseDao->create(DTO::DatabaseEntry::TextNote, title, filePath);
}

void TextNoteModel::update(const DTO::TextNote &note)
{

}

void TextNoteModel::update(qint64 id, QString title, QString body)
{

}

DTO::TextNote TextNoteModel::find(qint64 id)
{
    return {};
}

void TextNoteModel::erase(qint64 id)
{

}

}
