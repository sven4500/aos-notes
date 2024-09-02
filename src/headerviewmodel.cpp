#include "headerviewmodel.h"

HeaderViewModel::HeaderViewModel(QObject *parent) : QObject(parent)
{

}

const QString &HeaderViewModel::noteTitle() const
{
    return m_noteTitle;
}

void HeaderViewModel::setNoteTitle(const QString &newNoteTitle)
{
    if (m_noteTitle == newNoteTitle)
        return;
    m_noteTitle = newNoteTitle;
    emit noteTitleChanged();
}
