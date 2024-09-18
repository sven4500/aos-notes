#ifndef AUDIONOTE_H
#define AUDIONOTE_H

#include <QString>

namespace DTO {

struct AudioNote
{
    explicit AudioNote(qint64 id, QString title, QString filePath)
        : id(id)
        , title(title)
        , filePath(filePath)
    {

    }

    qint64 id = 0;
    QString title;
    QString filePath;

};

}

#endif // AUDIONOTE_H
