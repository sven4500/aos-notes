#include <QDebug>

#include "abstractnoteviewmodel.h"

namespace ViewModels {

AbstractNoteViewModel::AbstractNoteViewModel(QObject *parent) : QObject(parent)
{

}

int AbstractNoteViewModel::id() const
{
    return m_id;
}

void AbstractNoteViewModel::setId(int newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    emit idChanged();
}

const QString &AbstractNoteViewModel::title() const
{
    return m_title;
}

void AbstractNoteViewModel::setTitle(const QString &newTitle)
{
    if (m_title == newTitle)
        return;
    m_title = newTitle;
    emit titleChanged();
}

}
