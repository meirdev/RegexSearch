#ifndef __SEARCH_ISEARCH_H__
#define __SEARCH_ISEARCH_H__

#include <string>

#include "Search/SearchResult.h"

class ISearch
{
public:
    virtual ~ISearch() = default;
    virtual SearchResult search(const std::string& _search, const std::string& _text) = 0;
    virtual void setCaseSensitive(bool _mode) = 0;
    virtual void setWholeWords(bool _mode) = 0;
};

#endif // __SEARCH_ISEARCH_H__