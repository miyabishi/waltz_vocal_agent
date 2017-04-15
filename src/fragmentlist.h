#ifndef FRAGMENTSETS_H
#define FRAGMENTSETS_H

#include <QList>
#include "waltzvocalagent_global.h"
#include "samephonemefragmentsets.h"

namespace waltz
{
    namespace agent
    {
        class WALTZVOCALAGENTSHARED_EXPORT FragmentList
        {
        public:
            FragmentList();
            FragmentList(const FragmentList& aOther);
            FragmentList& operator=(const FragmentList& aOther);

        public:
            void appendSamePhonemeFragmentSets(
                    const SamePhonemeFragmentSets& aSamePhonemFragmentSets);
            SamePhonemeFragmentSets at(int aPosition) const;
            int length() const;

        private:
            QList<SamePhonemeFragmentSets> mSamePhonemeFragmentSets_;
        };
    } // namespace agent
} // namespace waltz

#endif // FRAGMENTCONTAINER_H
