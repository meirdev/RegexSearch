#ifndef __SEARCH_REGEX_SEARCH_H__
#define __SEARCH_REGEX_SEARCH_H__

#include "Search/ISearch.h"

class RegexSearch : public ISearch
{
public:
    SearchResult search(const std::string& _search, const std::string& _text);
};

#endif // __SEARCH_REGEX_SEARCH_H__