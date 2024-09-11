#ifndef TEXTNOTEMODEL_H
#define TEXTNOTEMODEL_H

#include <optional>

#include <QDir>
#include <QObject>

#include "dto/textnote.h"

namespace DAO {
class DatabaseDAO;
}

namespace Models {

class TextNoteModel : public QObject
{
    Q_OBJECT

public:
    explicit TextNoteModel(QObject *parent = nullptr);

    std::optional<DTO::TextNote> find(qint64 id) const;

    void insert(QString title, QString body);

    void remove(qint64 id);

    void update(qint64 id, QString title, QString body);

private:
    static QDir const WorkingDir;

    DAO::DatabaseDAO* m_databaseDao = nullptr;

};

}

#endif // TEXTNOTEMODEL_H
