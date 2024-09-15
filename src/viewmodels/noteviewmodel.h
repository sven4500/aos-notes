#ifndef NOTEVIEWMODEL_H
#define NOTEVIEWMODEL_H

#include <QObject>
#include <QString>

namespace ViewModels {

class NoteViewModel : public QObject
{
    Q_OBJECT

signals:
    void idChanged();
    void titleChanged();

public:
    Q_PROPERTY(qint64 id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)

    explicit NoteViewModel(QObject *parent = nullptr);

    virtual void insertNote() = 0;
    virtual void removeNote() = 0;

    qint64 id() const;
    void setId(qint64 newId);

    const QString &title() const;
    void setTitle(const QString &newTitle);

protected:
    qint64 m_id = 0;
    QString m_title;

};

}

#endif // NOTEVIEWMODEL_H
