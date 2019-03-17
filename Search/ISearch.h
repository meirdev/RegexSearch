#ifndef __ISEARCH_H__
#define __ISEARCH_H__

#include <string>

#include "Search/SearchResult.h"

class ISearch
{
public:
    virtual ~ISearch() = default;
    virtual SearchResult search(const std::string& _search, const std::string& _text) = 0;
};

#endif // __ISEARCH_H__