#ifndef DATABASEENTRY_H
#define DATABASEENTRY_H

#include <QDateTime>
#include <QObject>
#include <QString>

namespace DTO {

struct DatabaseEntry
{
    Q_GADGET

public:
    enum NoteType {
        TextNote,
        SketchNote,
        AudioNote
    };
    Q_ENUM(NoteType)

    qint64 id;
    QString title;
    QString media;
    QDateTime createdAt;
    QDateTime modifiedAt;
};

}

#endif // DATABASEENTRY_H
