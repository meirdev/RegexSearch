#ifndef __STYLE_ACK_H__
#define __STYLE_ACK_H__

#include <vector>
#include <set>
#include <map>

#include "Style/IStyle.h"

class Ack : public IStyle
{
public:
    std::string result(const std::string& _fileName, const std::string& _fileContent, const SearchResult& _results);
private:
    typedef struct
    {
        size_t m_start;
        size_t m_end;
        bool   m_results;
    } LineIndex;
private:
    std::vector<LineIndex> getLinesIndex(const std::string& _file);
    std::map<size_t, std::string> highlightResults(const std::string& _file, const SearchResult& _results, std::vector<LineIndex>& _lines);
    std::set<size_t> getLinesNumber(size_t _lines, const std::map<size_t, std::string>& _results);
    std::string styleFilename(const std::string& _filename);
    std::string styleLineNumber(size_t _line);
    std::string styleMatch(const std::string& _match);
};

#endif // __STYLE_ACK_H__