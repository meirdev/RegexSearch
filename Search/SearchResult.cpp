#include "Search/SearchResult.h"

void SearchResult::add(size_t _start, size_t _end)
{
    m_position.push_back({ /* .m_start= */ _start, /* .m_end= */ _end });
}

std::vector<SearchResult::Result>::const_iterator SearchResult::begin() const
{
    return m_position.begin();
}

std::vector<SearchResult::Result>::const_iterator SearchResult::end() const
{
    return m_position.end();
}

size_t SearchResult::size() const
{
    return m_position.size();
}