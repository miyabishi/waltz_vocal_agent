#ifndef SAMEPHONEMEFRAGMENTSETS_H
#define SAMEPHONEMEFRAGMENTSETS_H

#include <QList>
#include "waltzvocalagent_global.h"
#include "fragmentdata.h"

namespace waltz
{
    namespace agent
    {
        class WALTZVOCALAGENTSHARED_EXPORT SamePhonemeFragmentSets
        {
        public:
            SamePhonemeFragmentSets();
            SamePhonemeFragmentSets(const SamePhonemeFragmentSets& aOther);
            SamePhonemeFragmentSets& operator=(const SamePhonemeFragmentSets& aOther);
            void append(const FragmentData& aFragment);
            bool isEmpty() const;
            int length() const;
            FragmentData at(int aPosition) const;

        private:
            QList<FragmentData> mSamePhonemeFragmentSets_;
        };
    } // namespace agent
} // namespace waltz

#endif // SAMEPHONEMEFRAGMENTSETS_H
