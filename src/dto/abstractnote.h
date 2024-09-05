#ifndef ABSTRACTNOTE_H
#define ABSTRACTNOTE_H

#include <QString>
#include <QDateTime>

struct AbstractNote
{
    qint64 id;
    QString title;
    QDateTime createdAt;
    QDateTime modifiedAt;
};

#endif // ABSTRACTNOTE_H
