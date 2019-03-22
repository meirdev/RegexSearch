#include <fstream>

#include "FileSystem/Local/LocalFile.h"

static inline size_t GetFileSize(std::ifstream& file)
{
    size_t currentPosition = file.tellg();

    file.seekg(0, std::ios_base::end);

    size_t fileSize = file.tellg();

    file.seekg(currentPosition, std::ios_base::beg);

    return fileSize;
}

std::shared_ptr<char> LocalFile::getContent(const std::string& _fileName)
{
    std::shared_ptr<char> m_buffer;

    try
    {
        std::ifstream file(_fileName, std::fstream::binary);

        size_t fileSize = GetFileSize(file);

        m_buffer = std::shared_ptr<char>(new char[fileSize]);

        file.read(m_buffer.get(), fileSize);
    }
    catch (...)
    {
        m_buffer = std::shared_ptr<char>(nullptr);
    }

    return m_buffer;
}