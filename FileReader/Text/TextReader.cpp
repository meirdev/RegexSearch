#include "FileReader/Text/TextReader.h"

std::string TextReader::read(std::shared_ptr<char> _fileBuffer)
{
    return _fileBuffer.get();
}