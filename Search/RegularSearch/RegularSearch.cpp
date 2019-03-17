#include <algorithm>

#include "Search/RegularSearch/RegularSearch.h"

SearchResult RegularSearch::search(const std::string& _search, const std::string& _text)
{
    SearchResult results;

    size_t startIndex, endIndex = 0;

    auto start = _text.begin();
    auto end   = _text.end();

    while (true)
    {
        auto result = std::search(start+endIndex, end, _search.begin(), _search.end());

        if (result == end)
        {
            break;
        }
        else
        {
            startIndex = std::distance(start, result);
            endIndex   = startIndex+_search.size();

            results.add(startIndex, endIndex);
        }
    }

    return results;
}