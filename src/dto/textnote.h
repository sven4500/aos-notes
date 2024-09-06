#ifndef TEXTNOTE_H
#define TEXTNOTE_H

#include <QString>

namespace DTO {

struct TextNote
{
    qint64 id;
    QString title;
    QString body;
};

}

#endif // TEXTNOTE_H
