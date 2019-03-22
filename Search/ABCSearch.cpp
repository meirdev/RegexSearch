#include "Search/ABCSearch.h"

ABCSearch::ABCSearch()
: m_caseSensitive(false)
, m_wholeWords(false)
{
}

void ABCSearch::setCaseSensitive(bool _mode)
{
    m_caseSensitive = _mode;
}

void ABCSearch::setWholeWords(bool _mode)
{
    m_wholeWords = _mode;
}