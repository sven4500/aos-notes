#ifndef TEXTNOTEVIEWMODEL_H
#define TEXTNOTEVIEWMODEL_H

#include <QObject>

#include "noteviewmodel.h"

namespace Models {
class TextNoteModel;
}

namespace ViewModels {

class TextNoteViewModel: public NoteViewModel
{
    Q_OBJECT

signals:
    void bodyChanged();

public:
    Q_PROPERTY(QString body READ body WRITE setBody NOTIFY bodyChanged)

    explicit TextNoteViewModel(Models::TextNoteModel* model, QObject *parent = nullptr);

    virtual void insertNote();
    virtual void removeNote();

    const QString &body() const;
    void setBody(const QString &newBody);

private:
    void onIdChanged();

    QString m_body;
    Models::TextNoteModel* m_model = nullptr;

};

}

#endif // TEXTNOTEVIEWMODEL_H
