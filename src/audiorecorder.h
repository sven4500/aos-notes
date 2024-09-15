#ifndef AUDIORECORDER_H
#define AUDIORECORDER_H

#include <QAudioRecorder>
#include <QObject>

namespace Managers {

class AudioRecorder : public QAudioRecorder
{
    Q_OBJECT

public:
    AudioRecorder(QObject* parent = nullptr);

};

}

#endif // AUDIORECORDER_H
