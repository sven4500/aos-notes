#ifndef TEXTNOTEVIEWMODEL_H
#define TEXTNOTEVIEWMODEL_H

#include <QObject>

namespace ViewModels {

class TextNoteViewModel : public QObject
{
    Q_OBJECT

signals:
    void idChanged();
    void titleChanged();
    void bodyChanged();

public:
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString body READ body WRITE setBody NOTIFY bodyChanged)

    explicit TextNoteViewModel(QObject *parent = nullptr);

    Q_INVOKABLE void saveNote();

    int id() const;
    void setId(int newId);

    const QString &title() const;
    void setTitle(const QString &newTitle);

    const QString &body() const;
    void setBody(const QString &newBody);

private:
    QString m_title;
    QString m_body;
    int m_id = 0;

};

}

#endif // TEXTNOTEVIEWMODEL_H
