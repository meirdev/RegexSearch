#include <sstream>

#include "Style/Ack/Ack.h"

inline std::string Ack::lineNumber(size_t _line)
{
    return "\x1b[1m\x1b[33m" + std::to_string(_line) + "\x1b[0m";
}

inline std::string Ack::fileName(const std::string& _fileName)
{
    return "\x1b[1m\x1b[32m" + _fileName + "\x1b[0m";
}

inline std::string Ack::line(const std::string& _line)
{
    return _line;
}

inline std::string Ack::line(const std::string& _line, const SearchResult& _results)
{
    std::string lineResult;

    size_t start = 0;

    for (auto& r : _results)
    {
        lineResult += _line.substr(start, r.m_start - start);
        lineResult += "\x1b[30m\x1b[43m" + _line.substr(r.m_start, r.m_end - r.m_start) + "\x1b[0m";

        start = r.m_end;
    }

    lineResult += _line.substr(start);

    return lineResult;
}