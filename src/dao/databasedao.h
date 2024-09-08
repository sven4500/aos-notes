#ifndef DATABASEMODEL_H
#define DATABASEMODEL_H

#include <optional>

#include <QDir>
#include <QObject>
#include <QSqlDatabase>

#include "dto/databaseentry.h"

namespace DAO {

class DatabaseDAO : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseDAO(QObject *parent = nullptr);

    void create(DTO::DatabaseEntry::NoteType noteType, QString title, QString media);

    std::optional<DTO::DatabaseEntry> find(qint64 id);

    QList<DTO::DatabaseEntry> list() const;

    void update(qint64 id);

    void erase(qint64 id);

private:
    static const QString DatabaseFilename;
    static const QString DriverName;

    QSqlDatabase m_database;

};

}

#endif // DATABASEMODEL_H
