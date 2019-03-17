#ifndef __FILE_SYSTEM_LOCAL_DIRECTORY_H__
#define __FILE_SYSTEM_LOCAL_DIRECTORY_H__

#include <dirent.h>

#include "FileSystem/ABCDirectory.h"

class LocalDirectory : public ABCDirectory
{
public:
    LocalDirectory(const std::string& _directory);
    ~LocalDirectory();
private:
    DIR* m_directory;
};

#endif // __FILE_SYSTEM_LOCAL_DIRECTORY_H__