#ifndef __STYLE_ISTYLE_H__
#define __STYLE_ISTYLE_H__

#include <string>

#include "Search/SearchResult.h"

class IStyle
{
public:
    virtual ~IStyle() = default;
    virtual std::string lineNumber(size_t _line) = 0;
    virtual std::string fileName(const std::string& _fileName) = 0;
    virtual std::string line(const std::string& _line) = 0;
    virtual std::string line(const std::string& _line, const SearchResult& _results) = 0;
};

#endif // __STYLE_ISTYLE_H__