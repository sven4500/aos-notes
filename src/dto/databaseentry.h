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

    explicit DatabaseEntry(qint64 id, NoteType type, QString title, QString media, QDateTime createdAt, QDateTime modifiedAt)
        : id(id)
        , type(type)
        , title(title)
        , media(media)
        , createdAt(createdAt)
        , modifiedAt(modifiedAt)
    {

    }

    qint64 id;
    NoteType type;
    QString title;
    QString media;
    QDateTime createdAt;
    QDateTime modifiedAt;

};

}

#endif // DATABASEENTRY_H
