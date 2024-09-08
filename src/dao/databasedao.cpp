#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardPaths>

#include "databasedao.h"

namespace DAO {

QString const DatabaseDAO::DriverName = "QSQLITE";
QString const DatabaseDAO::DatabaseFilename = "notes.sqlite";

DatabaseDAO::DatabaseDAO(QObject *parent)
    : QObject(parent)
{
    if (!QSqlDatabase::isDriverAvailable(DriverName))
        throw std::runtime_error(QString("no provider exists for %1").arg(DriverName).toStdString());

    // INFO: https://stackoverflow.com/questions/2241808/checking-if-a-folder-exists-and-creating-folders-in-qt-c
    QDir const workingDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) +
            QDir::separator() + "notes";
    QDir().mkdir(workingDir.path());

    m_database = QSqlDatabase::addDatabase(DriverName);
    m_database.setDatabaseName(workingDir.filePath(DatabaseFilename));

    if (!m_database.open())
        throw std::runtime_error(QString("failed to open database at location %1").arg(workingDir.path()).toStdString());

    // INFO: https://stackoverflow.com/questions/9342249/how-to-insert-a-unique-id-into-each-sqlite-row
    // INFO: https://stackoverflow.com/questions/62434913/how-to-create-a-table-in-qt-with-sqlite
    QSqlQuery query(m_database);
    query.exec("CREATE TABLE IF NOT EXISTS media (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
        "type INTEGER, title TEXT, media TEXT, created DATETIME, modified DATETIME);");
}

void DatabaseDAO::create(DTO::DatabaseEntry::NoteType noteType, QString title, QString media)
{
    qDebug() << "create note" << title << noteType;

    QSqlQuery query(m_database);
    query.prepare("INSERT INTO media (type, title, media, created, modified) "
        "VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(noteType);
    query.addBindValue(title);
    query.addBindValue(media);
    query.addBindValue(QDateTime::currentDateTime());
    query.addBindValue(QDateTime::currentDateTime());
    query.exec();
}

QList<DTO::DatabaseEntry> DatabaseDAO::list() const
{
    qDebug() << "list database";

    QSqlQuery query(m_database);
    query.prepare("SELECT * FROM media");
    query.exec();

    QList<DTO::DatabaseEntry> list;
    while(query.next()) {
        //list.append({});
    }

    return {};
}

}
