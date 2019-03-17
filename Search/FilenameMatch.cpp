#include "Search/FilenameMatch.h"

bool FilenameMatch::matchByExtension(const std::string& _filename, const std::string& _extension)
{
    size_t index = _filename.find_last_of('.');

    if (index == std::string::npos || index == _filename.size()-1)
    {
        return false;
    }

    std::string extension = _filename.substr(index+1);

    return _extension == extension;
}