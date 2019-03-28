#include <regex>
#include <iostream>

#include "Search/RegexSearch/RegexSearch.h"

SearchResult RegexSearch::search(const std::string& _search, const std::string& _text)
{
    SearchResult results;

    std::regex_constants::syntax_option_type flags = std::regex_constants::ECMAScript;
    
    if (m_caseSensitive)
    {
        flags |= std::regex_constants::icase;
    }

    std::regex expression(_search, flags);

    auto begin = _text.begin();
    auto end   = _text.end();

    size_t start = 0;

    std::smatch matchs;

    while (std::regex_search(begin, end, matchs, expression))
    {
        size_t startIndex = matchs.position();
        size_t endIndex   = startIndex+(*matchs.begin()).length();

        results.add(start+startIndex, start+endIndex);

        begin += endIndex;
        start += endIndex;
    }

    return results;
}