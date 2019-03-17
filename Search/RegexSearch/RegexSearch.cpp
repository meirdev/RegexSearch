#include <regex>
#include <iostream>

#include "Search/RegexSearch/RegexSearch.h"

SearchResult RegexSearch::search(const std::string& _search, const std::string& _text)
{
    SearchResult results;

    std::smatch matchs;
    std::regex  expression(_search);

    auto begin = _text.begin();
    auto end   = _text.end();

    while (std::regex_search(begin, end, matchs, expression))
    {
        size_t startIndex = matchs.position();
        size_t endIndex   = startIndex+(*matchs.begin()).length();

        results.add(startIndex, endIndex);

        begin += endIndex;
    }

    return results;
}