#ifndef TEXTNOTEVIEWMODEL_H
#define TEXTNOTEVIEWMODEL_H

#include <QObject>

#include "abstractnoteviewmodel.h"

namespace ViewModels {

class TextNoteViewModel : public AbstractNoteViewModel
{
    Q_OBJECT

signals:
    void bodyChanged();

public:
    Q_PROPERTY(QString body READ body WRITE setBody NOTIFY bodyChanged)

    explicit TextNoteViewModel(QObject *parent = nullptr);

    Q_INVOKABLE virtual void saveNote();

    const QString &body() const;
    void setBody(const QString &newBody);

private:
    QString m_body;

};

}

#endif // TEXTNOTEVIEWMODEL_H
