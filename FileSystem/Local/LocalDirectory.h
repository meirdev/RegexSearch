#ifndef __FILE_SYSTEM_LOCAL_DIRECTORY_H__
#define __FILE_SYSTEM_LOCAL_DIRECTORY_H__

#include "FileSystem/IDirectory.h"

class LocalDirectory : public IDirectory
{
public:
    std::vector<File> getFiles(const std::string& _directory);
};

#endif // __FILE_SYSTEM_LOCAL_DIRECTORY_H__