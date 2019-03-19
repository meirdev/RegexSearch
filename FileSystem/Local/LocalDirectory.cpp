#include <dirent.h>

#include "FileSystem/Local/LocalDirectory.h"

std::vector<LocalDirectory::File> LocalDirectory::getFiles(const std::string& _directory)
{
    DIR* m_directory = opendir(_directory.c_str());

    std::vector<LocalDirectory::File> files;

    if (!m_directory)
    {
        return files;
    }

    struct dirent* file;

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