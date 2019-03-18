#ifndef __SEARCH_EXTENSION_MATCH_H__
#define __SEARCH_EXTENSION_MATCH_H__

#include <string>
#include <vector>

class ExtensionMatch
{
public:
    bool match(const std::string& _filename);
    void add(const std::string& _extension);
private:
    std::vector<std::string> m_extensions;
};

#endif // __SEARCH_EXTENSION_MATCH_H__