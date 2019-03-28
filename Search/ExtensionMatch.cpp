#include <algorithm>
#include <regex>
#include <string.h>

#include "Search/ExtensionMatch.h"

static std::string toLower(std::string _string)
{
    for (auto& i : _string)
    {
        i = static_cast<char>(tolower(i));
    }

    return _string;
}

bool ExtensionMatch::match(const std::string& _filename)
{
    size_t index = _filename.find_last_of('.');

    index = (index == std::string::npos) ? 0 : index+1;
    
    std::string extension = _filename.substr(index);

    auto begin = m_extensions.begin();
    auto end   = m_extensions.end();

    auto result = std::find(begin, end, toLower(extension));

    return result != end;
}

void ExtensionMatch::add(const std::string& _extension)
{
    m_extensions.push_back(toLower(_extension));
}

bool ExtensionMatch::regexMatch(const std::string& _filename, const std::string& _format)
{
    if (_format == "")
    {
        return true;
    }

    static std::regex expression(_format);

    return std::regex_match(_filename, expression);
}