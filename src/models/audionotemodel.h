#ifndef AUDIONOTEMODEL_H
#define AUDIONOTEMODEL_H

#include <optional>

#include <QDir>
#include <QObject>
#include <QString>

#include "dto/audionote.h"

namespace DAO {
class DatabaseDAO;
}

namespace Models {

class AudioNoteModel: public QObject
{
    Q_OBJECT

public:
    explicit AudioNoteModel(DAO::DatabaseDAO* databaseDAO, QObject *parent = nullptr);

    std::optional<DTO::AudioNote> find(qint64 id) const;

    void insert(QString title);

    void remove(qint64 id);

    void update(qint64 id, QString title);

    static QDir const WorkingDir;
    static QString const TemporaryFilePath;

private:
    DAO::DatabaseDAO* m_databaseDAO = nullptr;

};

}

#endif // AUDIONOTEMODEL_H
