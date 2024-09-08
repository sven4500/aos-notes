#ifndef TEXTNOTEMODEL_H
#define TEXTNOTEMODEL_H

#include <QDir>
#include <QObject>

#include "dto/textnote.h"

namespace Models {
class DatabaseModel;

class TextNoteModel : public QObject
{
    Q_OBJECT

public:
    explicit TextNoteModel(QObject *parent = nullptr);

    void create(QString title, QString body);

    void update(DTO::TextNote const& note);
    void update(qint64 id, QString title, QString body);

    DTO::TextNote find(qint64 id);

    void erase(qint64 id);

private:
    static QDir const WorkingDir;

    DatabaseModel* m_databaseModel = nullptr;

};

}

#endif // TEXTNOTEMODEL_H