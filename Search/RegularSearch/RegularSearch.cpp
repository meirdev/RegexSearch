#include <algorithm>
#include <string.h>

#include "Search/RegularSearch/RegularSearch.h"

static inline bool CheckWholeWord(bool _check, size_t _char)
{
    return _check ? !isalpha(static_cast<int>(_char)) : false;
}

SearchResult RegularSearch::search(const std::string& _search, const std::string& _text)
{
    SearchResult results;

    size_t startIndex, endIndex = 0;

    auto start = _text.begin();
    auto end   = _text.end();

    size_t searchSize = _search.size();
    size_t textSize   = _text.size();

    auto searchCompare = [&](char i, char j) -> bool {
        return !m_caseSensitive ? tolower(i) == tolower(j) : i == j;
    };

    while (true)
    {
        auto result = std::search(start+endIndex, end, _search.begin(), _search.end(), searchCompare);

        if (result == end)
        {
            break;
        }
        else
        {
            startIndex = std::distance(start, result);
            endIndex   = startIndex+searchSize;

            if (!m_wholeWords || (CheckWholeWord(startIndex > 0, start[startIndex-1]) && CheckWholeWord(endIndex < textSize, start[endIndex])) )
            {
                results.add(startIndex, endIndex);
            }
        }
    }

    return results;
}