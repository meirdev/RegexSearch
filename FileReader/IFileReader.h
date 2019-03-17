#ifndef __FILE_READER_IFILE_READER_H__
#define __FILE_READER_IFILE_READER_H__

#include <string>

class IFileReader
{
public:
    virtual ~IFileReader() = default;
    virtual std::string read(char* _fileBuffer) = 0;
};

#endif // __FILE_READER_IFILE_READER_H__