#ifndef __STYLE_ACK_H__
#define __STYLE_ACK_H__

#include "Style/IStyle.h"

class Ack : public IStyle
{
public:
    std::string result(const std::string& _fileName, const std::string& _fileContent, const SearchResult& _results);
};

#endif // __STYLE_ACK_H__