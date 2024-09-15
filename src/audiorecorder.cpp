#include "audiorecorder.h"

namespace Managers {

AudioRecorder::AudioRecorder(QObject* parent)
    : QAudioRecorder(parent)
{
    QAudioEncoderSettings audioSettings;
    audioSettings.setCodec("audio/PCM");
    audioSettings.setQuality(QMultimedia::HighQuality);

    setEncodingSettings(audioSettings);
    setContainerFormat("wav");
}

}
