#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <QObject>
#include <QAudioOutput>
#include <fragmentdata.h>
#include <QBuffer>
#include <QPointer>

namespace waltz
{
    namespace example
    {
        class SoundPlayer : public QObject
        {
            Q_OBJECT
        public:
            SoundPlayer(QObject* aParent);
            void start(QIODevice* aIODevice,
                       const int sampleRate,
                       const int sampleSize);
        private slots:
            void stateChangedHandler(QAudio::State);
        private:
            QPointer<QAudioOutput> mAudioOutput_;
        };

    } // namespace engine
} // namespace waltz

#endif // SOUNDPLAYER_H
