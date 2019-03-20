#include <iostream>
#include <sstream>

#include "Style/Ack/Ack.h"
#include "Configuration.h"

extern Configuration* g_configuration;

std::vector<Ack::LineIndex> Ack::getLinesIndex(const std::string& _file)
{
    std::vector<Ack::LineIndex> lines;

    size_t start = 0;

    while (true)
    {
        size_t end = _file.find('\n', start);

        if (end == std::string::npos)
        {
            lines.push_back({ start, _file.size() });

            break;
        }

        lines.push_back({ start, end, false });

        start = end+1;
    }

    return lines;
}

std::map<size_t, std::string> Ack::highlightResults(const std::string& _file, const SearchResult& _results, std::vector<LineIndex>& _lines)
{
    std::map<size_t, std::string> highlightResults;

    auto currentResult = _results.begin();
    auto endResult     = _results.end();

    for (size_t lineIndex = 0, nLines = _lines.size(); lineIndex < nLines; ++lineIndex)
    {
        auto& currentLine = _lines[lineIndex];

        size_t startIndex = currentLine.m_start;

        bool newResult = false;

        std::stringstream lineResult;

        while (currentResult != endResult && currentLine.m_start <= currentResult->m_start && currentResult->m_end <= currentLine.m_end)
        {
            newResult = true;

            lineResult << _file.substr(startIndex, currentResult->m_start - startIndex);
            lineResult << styleMatch(_file.substr(currentResult->m_start, currentResult->m_end - currentResult->m_start));

            if (currentResult+1 != endResult && (currentResult+1)->m_end <= currentLine.m_end)
            {
                startIndex = currentResult->m_end;
            }
            else
            {
                lineResult << _file.substr(currentResult->m_end, currentLine.m_end - currentResult->m_end);
            }

            ++currentResult;
        }

        if (newResult)
        {
            highlightResults[lineIndex+1] = lineResult.str();
            
            currentLine.m_results = true;
        }
    }

    return highlightResults;
}

std::set<size_t> Ack::getLinesNumber(size_t _lines, const std::map<size_t, std::string>& _results)
{
    std::set<size_t> printLines;

    for (auto& line : _results)
    {
        size_t low = line.first;

        if (low >= g_configuration->m_beforeContext)
        {
            low -= g_configuration->m_beforeContext;
        }

        size_t high = line.first;

        if (high + g_configuration->m_afterContext <= _lines)
        {
            high += g_configuration->m_afterContext;
        }

        for (; low <= high; ++low)
        {
            printLines.insert(low);
        }
    }

    return printLines;
}

std::string Ack::result(const std::string& _fileName, const std::string& _fileContent, const SearchResult& _results)
{
    std::stringstream output;

    std::string styleFileName = styleFilename(_fileName);

    if (_results.size() == 0)
    {
        if (g_configuration->m_allFiles)
        {
            output << styleFileName << std::endl;

            return output.str();
        }
        else
        {
            return output.str();
        }
    }

    if (g_configuration->m_onlyFilename)
    {
        output << styleFileName << std::endl;

        return output.str();
    }

    std::vector<Ack::LineIndex> lines = getLinesIndex(_fileContent);
    std::map<size_t, std::string> results = highlightResults(_fileContent, _results, lines);
    std::set<size_t> linesNumber = getLinesNumber(lines.size(), results);

    if (!g_configuration->m_inlineFilename)
    {
        output << styleFileName << std::endl;
    }

    for (auto& i : linesNumber)
    {
        if (g_configuration->m_inlineFilename)
        {
            output << styleFileName << ":";
        }

        output << styleLineNumber(i);

        if (lines[i-1].m_results)
        {
            output << ":" << results[i] << std::endl;
        }
        else
        {
            output << "-" << _fileContent.substr(lines[i-1].m_start, lines[i-1].m_end - lines[i-1].m_start) << std::endl;
        }
    }

    return output.str();
}

inline std::string Ack::styleFilename(const std::string& _filename)
{
    return "\x1b[1m\x1b[32m" + _filename + "\x1b[0m";
}

inline std::string Ack::styleLineNumber(size_t _line)
{
    return "\x1b[1m\x1b[33m" + std::to_string(_line) + "\x1b[0m";
}

inline std::string Ack::styleMatch(const std::string& _match)
{
    return "\x1b[30m\x1b[43m" + _match + "\x1b[0m";
}