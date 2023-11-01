// #include <my_filesystem.hpp>
#include <main_header.hpp>


unsigned int GetFileSize(std::string filename)
{
    std::filesystem::path filePath("path_to_file.txt");

    if (std::filesystem::exists(filePath))
    {
        unsigned int file_size = std::filesystem::file_size(filePath);
    }
    return 0;
}


std::filesystem::directory_entry getFileInfo()
{
    std::filesystem::directory_entry entry("path_to_file.txt");
    return entry;
}


void serialize(const std::filesystem::path& filePath, std::ostream& os)
{
    std::ifstream in(filePath, std::ios::binary);
    if (!in)
    {
        std::cerr << "Failed to open file for serialization." << std::endl;
        return;
    }

    os << filePath.filename().string() << '\n';
    os << filePath.string() << '\n';
    os << std::filesystem::file_size(filePath) << '\n';
    os << std::filesystem::last_write_time(filePath).time_since_epoch().count() << '\n';

    os << in.rdbuf();

    in.close();
}

std::string prepareFile(const std::string FilePath)
{
    std::stringstream socketStream;
    serialize(FilePath, socketStream);
    std::string serializedData = socketStream.str();
    return serializedData;
}