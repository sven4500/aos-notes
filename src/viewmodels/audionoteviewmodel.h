#ifndef AUDIONOTEVIEWMODEL_H
#define AUDIONOTEVIEWMODEL_H

#include <QObject>

#include "noteviewmodel.h"

namespace Models {
class AudioNoteModel;
}

namespace ViewModels {

class AudioNoteViewModel: public NoteViewModel
{
    Q_OBJECT

public:
    Q_PROPERTY(QString outputLocation READ outputLocation CONSTANT)
    Q_PROPERTY(QString mediaPath READ mediaPath WRITE setMediaPath NOTIFY mediaPathChanged)

    explicit AudioNoteViewModel(Models::AudioNoteModel* model, QObject *parent = nullptr);

    virtual void insertNote();
    virtual void removeNote();

    Q_INVOKABLE static QString parseTime(int milliseconds);

    const QString &outputLocation() const;

    const QString &mediaPath() const;
    void setMediaPath(const QString &newMediaPath);

signals:
    void mediaPathChanged();

private slots:
    void onIdChanged();

private:
    Models::AudioNoteModel* m_model = nullptr;

    QString m_mediaPath;
};

}

#endif // AUDIONOTEVIEWMODEL_H
