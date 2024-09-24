#ifndef SKETCHNOTEMODEL_H
#define SKETCHNOTEMODEL_H

#include <optional>

#include <QDir>
#include <QObject>

#include "dto/sketchnote.h"

namespace DAO {
class DatabaseDAO;
}

namespace Models
{

class SketchNoteModel : public QObject
{
    Q_OBJECT

public:
    explicit SketchNoteModel(DAO::DatabaseDAO* databaseDAO, QObject *parent = nullptr);

    std::optional<DTO::SketchNote> find(qint64 id) const;

    void insert(QString title, QImage image);

    void remove(qint64 id);

    void update(qint64 id, QString title, QImage image);

    static QDir const WorkingDir;

private:
    DAO::DatabaseDAO* m_databaseDAO = nullptr;

};

}

#endif // SKETCHNOTEMODEL_H
