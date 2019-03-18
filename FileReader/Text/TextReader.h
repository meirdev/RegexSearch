#ifndef __FILE_READER_TEXT_READER_H__
#define __FILE_READER_TEXT_READER_H__

#include "FileReader/IFileReader.h"

class TextReader : public IFileReader
{
public:
    std::string read(std::shared_ptr<char> _fileBuffer);
};

#endif // __FILE_READER_TEXT_READER_H__