#include <iostream>
#include <sstream>
#include <vector>
#include <set>

#include "Style/Ack/Ack.h"
#include "Configuration.h"

extern Configuration* g_configuration;

std::string Ack::result(const std::string& _fileName, const std::string& _fileContent, const SearchResult& _results)
{
    std::vector<std::string> lines;
    std::set<size_t> matchs;

    if (_results.size() == 0)
    {
        return "";
    }

    size_t line = 1;

    size_t startIndex = 0;
    size_t resultIndex = 0;

    line = 1;

    auto beginResult = _results.begin();
    auto endResult   = _results.end();

    while (true)
    {
        size_t found = _fileContent.find('\n', startIndex);

        std::stringstream p;

        bool haveResult = false;

        while (beginResult+resultIndex != endResult && (beginResult+resultIndex)->m_start >= startIndex && (beginResult+resultIndex)->m_start <= found)
        {
            haveResult = true;

            size_t startResultIndex = (beginResult+resultIndex)->m_start;
            size_t endResultIndex   = (beginResult+resultIndex)->m_end;

            p << _fileContent.substr(startIndex, startResultIndex-startIndex);

            p << "\x1b[30m\x1b[43m" << _fileContent.substr(startResultIndex, endResultIndex - startResultIndex) << "\x1b[0m";

            if (beginResult+resultIndex+1 != _results.end() && (beginResult+resultIndex+1)->m_start < found)
            {
                p << _fileContent.substr(endResultIndex, (beginResult+resultIndex+1)->m_start - endResultIndex);

                endResultIndex += (beginResult+resultIndex+1)->m_start - endResultIndex;
            }
            else
            {
                p << _fileContent.substr(endResultIndex, found - endResultIndex);
            }

            startIndex = endResultIndex;

            ++resultIndex;
        }

        if (haveResult)
        {
            lines.push_back(p.str());
            matchs.insert(line);

            p.str("");
        }
        else
        {
            lines.push_back(_fileContent.substr(startIndex, found-startIndex));
        }

        if (found == std::string::npos)
        {
            break;
        }

        startIndex = found+1;

        ++line;
    }

    std::set<size_t> k;

    for (auto& i : matchs)
    {
        size_t low  = (i < g_configuration->m_beforeContext) ? 1 : i - g_configuration->m_beforeContext;
        size_t high = (i + g_configuration->m_afterContext > line - 1) ? line - 1 : i + g_configuration->m_afterContext;

        for (; low <= high; ++low)
        {
            k.insert(low);
        }
    }

    std::stringstream y;

    y << "\x1b[1m\x1b[32m" << _fileName << "\x1b[0m" << std::endl;

    for (auto& i : k)
    {
        //y << "\x1b[1m\x1b[32m" << _fileName << "\x1b[0m" << ":";

        if (matchs.find(i) == matchs.end())
        {
            y << "\x1b[1m\x1b[33m" << i << "\x1b[0m" << "-" << lines[i-1] << std::endl;
        }
        else
        {
            y << "\x1b[1m\x1b[33m" << i << "\x1b[0m" << ":" << lines[i-1] << std::endl;
        }
    }

    return y.str();
}