#ifndef AUDIONOTEMODEL_H
#define AUDIONOTEMODEL_H

#include <QDir>
#include <QObject>

namespace DAO {
class DatabaseDAO;
}

namespace Models {

class AudioNoteModel: public QObject
{
    Q_OBJECT

public:
    explicit AudioNoteModel(DAO::DatabaseDAO* databaseDAO, QObject *parent = nullptr);

    static QDir const WorkingDir;
    static QString const TemporaryFilePath;

private:
    DAO::DatabaseDAO* m_databaseDAO = nullptr;

};

}

#endif // AUDIONOTEMODEL_H
