#ifndef WAVFILEHEADERSTRUCTURE_H
#define WAVFILEHEADERSTRUCTURE_H

namespace waltz
{
    namespace agent
    {
        namespace Wave
        {
            struct chunk
            {
                char        id[4];
                quint32     size;
            };

            struct RIFFHeader
            {
                chunk       descriptor;     // "RIFF"
                char        type[4];        // "WAVE"
            };

            struct WAVEHeader
            {
                chunk       descriptor;
                quint16     audioFormat;
                quint16     numChannels;
                quint32     sampleRate;
                quint32     byteRate;
                quint16     blockAlign;
                quint16     bitsPerSample;
            };

            struct DATAHeader
            {
                chunk       descriptor;
            };

            struct WavFileHeaderStructure
            {
                RIFFHeader  riff;
                WAVEHeader  wave;
            };
        } // namespace Wave
    } // namespace agent
} // namespace waltz

#endif // WAVFILEHEADERSTRUCTURE_H
