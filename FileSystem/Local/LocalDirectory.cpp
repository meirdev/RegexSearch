#include <stdexcept>
#include <dirent.h>

#include "FileSystem/Local/LocalDirectory.h"

std::vector<LocalDirectory::File> LocalDirectory::getFiles(const std::string& _directory)
{
    DIR* m_directory = opendir(_directory.c_str());

    if (!m_directory)
    {
        throw std::runtime_error("can't open dir.");
    }

    struct dirent* file;

    std::vector<LocalDirectory::File> files;

    while ((file = readdir(m_directory)) != 0)
    {
        std::string fileName = file->d_name;

        if (fileName != "." && fileName != "..")
        {
            files.push_back({ fileName, (file->d_type == DT_DIR) });
        }
    }

    closedir(m_directory);

    return files;
}