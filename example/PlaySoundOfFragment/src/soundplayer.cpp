#include "soundplayer.h"
#include <QtDebug>
#include <QEventLoop>

using namespace waltz::example;

SoundPlayer::SoundPlayer(QObject* aParent)
    : QObject(aParent)
    , mAudioOutput_(0)
{
}
void SoundPlayer::start(QIODevice* aIODevice,
                        const int aSampleRate,
                        const int aSampleSize)
{
    QAudioFormat format;
    format.setSampleRate(aSampleRate);
    format.setChannelCount(1);
    format.setSampleSize(aSampleSize);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    if (!info.isFormatSupported(format)) {
        qWarning() << "Raw audio format not supported by backend, cannot play audio.";
        return;
    }

    mAudioOutput_ = new QAudioOutput(format, this);
    mAudioOutput_->stop();
    connect(mAudioOutput_, SIGNAL(stateChanged(QAudio::State)), this, SLOT(stateChangedHandler(QAudio::State)));
    mAudioOutput_->start(aIODevice);
}

void SoundPlayer::stateChangedHandler(QAudio::State aNewState)
{
    qDebug() << Q_FUNC_INFO << aNewState;
    if (aNewState != QAudio::StoppedState)
    {
        return;
    }

    if (mAudioOutput_->error() == QAudio::NoError) {
        return;
    }

    qWarning("audio output error");
    mAudioOutput_->stop();
}

