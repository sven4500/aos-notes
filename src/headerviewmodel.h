#ifndef HEADERVIEWMODEL_H
#define HEADERVIEWMODEL_H

#include <QObject>

class HeaderViewModel : public QObject
{
    Q_OBJECT

signals:
    void noteTitleChanged();

public:
    enum HeaderType {
        MainHeader,
        NoteHeader
    };
    Q_ENUM(HeaderType)

    Q_PROPERTY(QString noteTitle READ noteTitle WRITE setNoteTitle NOTIFY noteTitleChanged)

    explicit HeaderViewModel(QObject *parent = nullptr);

    const QString &noteTitle() const;
    void setNoteTitle(const QString &newNoteTitle);

private:
    QString m_noteTitle;

};

#endif // HEADERVIEWMODEL_H
