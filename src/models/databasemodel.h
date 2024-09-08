#ifndef DATABASEMODEL_H
#define DATABASEMODEL_H

#include <optional>

#include <QDir>
#include <QObject>
#include <QSqlDatabase>

#include "dto/databaseentry.h"

namespace Models {

class DatabaseModel : public QObject
{
    Q_OBJECT

public:
    enum NoteType {
        TextNote,
        SketchNote,
        AudioNote
    };
    Q_ENUM(NoteType)

    explicit DatabaseModel(QObject *parent = nullptr);

    void create(NoteType noteType, QString title, QString media);
    std::optional<DTO::DatabaseEntry> find(qint64 id);
    void update(qint64 id);
    void erase(qint64 id);

private:
    static const QString DatabaseFilename;
    static const QString DriverName;

    QSqlDatabase m_database;

};

}

#endif // DATABASEMODEL_H
