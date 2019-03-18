#ifndef __FILE_SYSTEM_IFILE_H__
#define __FILE_SYSTEM_IFILE_H__

#include <string>
#include <memory>

class IFile
{
public:
    virtual ~IFile() = default;
    virtual std::shared_ptr<char> getContent(const std::string& _fileName) = 0;
};

#endif // __FILE_SYSTEM_IFILE_H__