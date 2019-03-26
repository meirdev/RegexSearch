#ifndef __STYLE_ACK_H__
#define __STYLE_ACK_H__

#include "Style/IStyle.h"

class Ack : public IStyle
{
public:
    std::string lineNumber(size_t _line);
    std::string fileName(const std::string& _fileName);
    std::string line(const std::string& _line);
    std::string line(const std::string& _line, const SearchResult& _results);
};

#endif // __STYLE_ACK_H__