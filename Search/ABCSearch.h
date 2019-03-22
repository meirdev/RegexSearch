#ifndef __SEARCH_ABCSEARCH_H__
#define __SEARCH_ABCSEARCH_H__

#include "Search/ISearch.h"

class ABCSearch : public ISearch
{
public:
    ABCSearch();
    void setCaseSensitive(bool _mode);
    void setWholeWords(bool _mode);
protected:
    bool m_caseSensitive;
    bool m_wholeWords;
};

#endif // __SEARCH_ABCSEARCH_H__