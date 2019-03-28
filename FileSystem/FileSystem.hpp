#ifdef __FILE_SYSTEM_H__

template<typename TDir, typename TFile>
FileSystem<TDir, TFile>::FileSystem()
{
}

template<typename TDir, typename TFile>
IFile* FileSystem<TDir, TFile>::getFile()
{
    return new TFile;
}

template<typename TDir, typename TFile>
IDirectory* FileSystem<TDir, TFile>::getDir()
{
    return new TDir;
}

#endif // __FILE_SYSTEM_H__