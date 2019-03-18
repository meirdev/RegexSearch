#ifndef __FILE_READER_IFILE_READER_H__
#define __FILE_READER_IFILE_READER_H__

#include <string>
#include <memory>

class IFileReader
{
public:
    virtual ~IFileReader() = default;
    virtual std::string read(std::shared_ptr<char> _fileBuffer) = 0;
};

#endif // __FILE_READER_IFILE_READER_H__