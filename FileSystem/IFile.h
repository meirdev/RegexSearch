#ifndef __FILE_SYSTEM_IFILE_H__
#define __FILE_SYSTEM_IFILE_H__

#include <string>

class IFile
{
public:
    virtual ~IFile() = default;
    virtual char* getContent(const std::string& _fileName) = 0;
};

#endif // __FILE_SYSTEM_IFILE_H__