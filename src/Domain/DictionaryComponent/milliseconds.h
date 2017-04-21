#ifndef MILLISECONDS_H
#define MILLISECONDS_H

namespace waltz
{
    namespace agent
    {
        namespace DictionaryComponent
        {

            class MilliSeconds
            {
            public:
                explicit MilliSeconds(double aValue);
                MilliSeconds(const MilliSeconds& aOther);
                MilliSeconds& operator=(const MilliSeconds& aOther);
            public:
                double value() const;
                double toSeconds() const;
                int    toArrayLength(int aSampleRate) const;
                int    toBitPosition(int aSampleRate, int aSampleSize) const;
            private:
                double mValue_;
            };

        } // namespace DictionaryComponent
    } // namespace agent
} // namespace waltz

#endif // MILLISECONDS_H
