#ifndef __STYLE_ISTYLE_H__
#define __STYLE_ISTYLE_H__

#include <string>

#include "Search/SearchResult.h"

class IStyle
{
public:
    virtual ~IStyle() = default;
    virtual std::string result(const std::string& _fileName, const std::string& _fileContent, const SearchResult& _results) = 0;
};

#endif // __STYLE_ISTYLE_H__