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
    Q_PROPERTY(int defaultId READ defaultId CONSTANT)

    explicit AbstractNoteViewModel(QObject *parent = nullptr);

    virtual void saveNote() = 0;

    int id() const;
    void setId(int newId);

    const QString &title() const;
    void setTitle(const QString &newTitle);

    int defaultId() const;

protected:
    QString m_title;
    int const m_defaultId = 0;
    int m_id = m_defaultId;

};

}

#endif // ABSTRACTNOTEVIEWMODEL_H
