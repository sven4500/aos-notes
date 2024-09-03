#ifndef ABSTRACTNOTEVIEWMODEL_H
#define ABSTRACTNOTEVIEWMODEL_H

#include <QObject>

namespace ViewModels {

class AbstractNoteViewModel : public QObject
{
    Q_OBJECT

signals:
    void idChanged();
    void titleChanged();

public:
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)

    explicit AbstractNoteViewModel(QObject *parent = nullptr);

    virtual void saveNote() = 0;

    int id() const;
    void setId(int newId);

    const QString &title() const;
    void setTitle(const QString &newTitle);

protected:
    QString m_title;
    int m_id = 0;

};

}

#endif // ABSTRACTNOTEVIEWMODEL_H
