#include "soundplayer.h"
#include <QtDebug>
#include <QEventLoop>

using namespace waltz::example;

SoundPlayer::SoundPlayer(QObject* aParent)
    : QObject(aParent)
    , mAudioOutput_(0)
    , mAudioBuffer_()
{
}
void SoundPlayer::play( const waltz::agent::FragmentData& aFragmentData)
{
    if (! mAudioOutput_.isNull())
    {
        QEventLoop loop;
        connect(mAudioOutput_, SIGNAL(destroyed(QObject*)), &loop, SLOT(quit()));
        loop.exec();

    }
    mAudioByteArray_ = QByteArray(aFragmentData.waveformRawData(), aFragmentData.waveformRawDataSize());
    mAudioBuffer_.setData(mAudioByteArray_);
    mAudioBuffer_.open(QIODevice::ReadOnly);

    QAudioFormat format;
    format.setSampleRate(aFragmentData.sampleRate());
    format.setChannelCount(1);
    format.setSampleSize(aFragmentData.sampleSize());
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
    mAudioOutput_->start(&mAudioBuffer_);
}

void SoundPlayer::stateChangedHandler(QAudio::State aNewState)
{
    switch (aNewState) {
    case QAudio::IdleState:
        mAudioOutput_->stop();
        mAudioOutput_->reset();
        mAudioBuffer_.close();
        delete mAudioOutput_;
        break;

    case QAudio::StoppedState:
        if (mAudioOutput_->error() != QAudio::NoError) {
            qWarning("audio output error");
            mAudioOutput_->stop();
            mAudioBuffer_.close();
            delete mAudioOutput_;
        }
        break;
    default:
        break;
    }
}

