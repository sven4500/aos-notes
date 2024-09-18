#include <QDateTime>
#include <QDebug>

#include "noteviewmodel.h"

namespace ViewModels {

NoteViewModel::NoteViewModel(QObject *parent)
    : QObject(parent)
{

}

qint64 NoteViewModel::id() const
{
    return m_id;
}

void NoteViewModel::setId(qint64 newId)
{
    qDebug() << "set new id" << newId;
    // INFO: always set new id because of bidirectional binding on Qml side
    m_id = newId;
    emit idChanged();
}

const QString &NoteViewModel::title() const
{
    return m_title;
}

void NoteViewModel::setTitle(const QString &newTitle)
{
    qDebug() << "set new title" << newTitle;
    if (m_title == newTitle)
        return;
    m_title = newTitle;
    emit titleChanged();
}

QString NoteViewModel::defaultTitle()
{
    return tr("New note") + " " + QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm");
}

}
