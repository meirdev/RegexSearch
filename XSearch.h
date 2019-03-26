#ifndef __X_SEARCH_H__
#define __X_SEARCH_H__

#include <string>

#include "Config.h"

class XSearch
{
public:
    XSearch();
    ~XSearch();
    void setSearchEngine(const std::string& _engine);
    void setFileSystem(const std::string& _fileSystem);
    void setStyle(const std::string& _style);
    void setContextLine(size_t _before, size_t _after);
    void setCaseSensitive(bool _state);
    void start(const std::string& _term, const std::string& _dir);
private:
    Config m_config;
};

#endif // __X_SEARCH_H__