#ifndef SKETCHNOTEMODEL_H
#define SKETCHNOTEMODEL_H

#include <QObject>

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

private:
    DAO::DatabaseDAO* m_databaseDAO = nullptr;

};

}

#endif // SKETCHNOTEMODEL_H
