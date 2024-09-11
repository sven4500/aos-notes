#ifndef TEXTNOTEVIEWMODEL_H
#define TEXTNOTEVIEWMODEL_H

#include <QObject>

namespace Models {
class TextNoteModel;
}

namespace ViewModels {

class TextNoteViewModel: public QObject
{
    Q_OBJECT

signals:
    void idChanged();
    void titleChanged();
    void bodyChanged();

public:
    Q_PROPERTY(qint64 id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString body READ body WRITE setBody NOTIFY bodyChanged)

    explicit TextNoteViewModel(Models::TextNoteModel* model = nullptr, QObject *parent = nullptr);

    Q_INVOKABLE void saveNote();
    Q_INVOKABLE void removeNote();

    qint64 id() const;
    void setId(qint64 newId);

    const QString &title() const;
    void setTitle(const QString &newTitle);

    const QString &body() const;
    void setBody(const QString &newBody);

private:
    void onIdChanged();

    qint64 m_id = 0;
    QString m_title;
    QString m_body;

    Models::TextNoteModel* m_model = nullptr;

};

}

#endif // TEXTNOTEVIEWMODEL_H
