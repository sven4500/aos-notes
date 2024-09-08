#ifndef DATABASEENTRY_H
#define DATABASEENTRY_H

#include <QDateTime>
#include <QString>

namespace DTO {

struct DatabaseEntry
{
    qint64 id;
    QString title;
    QString media;
    QDateTime createdAt;
    QDateTime modifiedAt;
};

}

#endif // DATABASEENTRY_H
