#ifndef __FILE_SYSTEM_I_FILE_SYSTEM_H__
#define __FILE_SYSTEM_I_FILE_SYSTEM_H__

#include <memory>

#include "FileSystem/IFile.h"
#include "FileSystem/IDirectory.h"

class IFileSystem
{
public:
    virtual IFile* getFile() = 0;
    virtual IDirectory* getDir() = 0;
};

#endif // __FILE_SYSTEM_I_FILE_SYSTEM_H__