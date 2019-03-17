#ifndef __FILE_SYSTEM_LOCAL_FILE_H__
#define __FILE_SYSTEM_LOCAL_FILE_H__

#include "FileSystem/IFile.h"

class LocalFile : public IFile
{
public:
    ~LocalFile();
    char* getContent(const std::string& _fileName);
private:
    char* m_buffer;
};

#endif // __FILE_SYSTEM_LOCAL_FILE_H__