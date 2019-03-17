#ifndef __SEARCH_FILENAME_MATCH_H__
#define __SEARCH_FILENAME_MATCH_H__

#include <string>

class FilenameMatch
{
public:
    static bool matchByExtension(const std::string& _filename, const std::string& _extension);
};

#endif // __SEARCH_FILENAME_MATCH_H__