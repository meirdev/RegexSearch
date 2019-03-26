#ifndef __FILE_SYSTEM_H__
#define __FILE_SYSTEM_H__

#include "FileSystem/IFileSystem.h"

template<typename TDir, typename TFile>
class FileSystem : public IFileSystem
{
public:
    FileSystem();
    IFile* getFile();
    IDirectory* getDir();
private:
    IDirectory* m_dir;
};

#include "FileSystem/FileSystem.hpp"

#endif // __FILE_SYSTEM_H__