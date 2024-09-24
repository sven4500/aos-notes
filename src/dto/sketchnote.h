#ifndef SKETCHNOTE_H
#define SKETCHNOTE_H

#include <QImage>
#include <QString>

namespace DTO {

struct SketchNote {
    qint64 id = 0;
    QString title;
    QImage image;
};

}

#endif // SKETCHNOTE_H
