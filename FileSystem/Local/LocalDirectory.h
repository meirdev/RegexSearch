#ifndef __FILE_SYSTEM_LOCAL_DIRECTORY_H__
#define __FILE_SYSTEM_LOCAL_DIRECTORY_H__

#include "FileSystem/IDirectory.h"

class LocalDirectory : public IDirectory
{
public:
    void open(const std::string& _directory);
    std::vector<File>::const_iterator begin() const;
    std::vector<File>::const_iterator end() const;
private:
    std::vector<File> m_files;
};

#endif // __FILE_SYSTEM_LOCAL_DIRECTORY_H__