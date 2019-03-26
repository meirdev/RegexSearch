#ifndef __FILE_SYSTEM_LOCAL_FILE_H__
#define __FILE_SYSTEM_LOCAL_FILE_H__

#include <fstream>

#include "FileSystem/IFile.h"

class LocalFile : public IFile
{
public:
    void open(const std::string& _fileName);
    void close();
    bool read(std::string& _buffer);
private:
    std::ifstream m_file;
};

#endif // __FILE_SYSTEM_LOCAL_FILE_H__