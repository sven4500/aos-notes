#ifndef TEXTNOTE_H
#define TEXTNOTE_H

#include <QString>

#include "abstractnote.h"

struct TextNote: public AbstractNote
{
    QString body;
};

#endif // TEXTNOTE_H
