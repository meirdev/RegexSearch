#ifndef __SEARCH_RESULT_H__
#define __SEARCH_RESULT_H__

#include <vector>

class SearchResult
{
private:
    typedef struct {
        size_t m_start;
        size_t m_end;
    } Result;
public:
    void add(size_t _start, size_t _end);
    std::vector<Result>::const_iterator begin() const;
    std::vector<Result>::const_iterator end() const;
    size_t size() const;
private:
    std::vector<Result> m_position;
};

#endif // __SEARCH_RESULT_H__