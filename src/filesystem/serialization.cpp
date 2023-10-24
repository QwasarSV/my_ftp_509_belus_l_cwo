#include <iostream>
#include <fstream>

#include <filesystem>

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


std::string Serialize(const std::filesystem::path& filePath)
{
    std::string outputFile;
    std::ofstream out(outputFile, std::ios::binary);
    std::ifstream in(filePath, std::ios::binary);

    if (!out || !in)
    {
        //big bad ? 
    }

    out << filePath.string() << '\n';
    out << std::filesystem::file_size(filePath) << '\n';
    out << std::filesystem::last_write_time(filePath).time_since_epoch().count() << '\n';
    out << in.rdbuf();
    in.close();
    out.close();
    return outputFile;
}


void deserialize(const std::string& inputFile, std::filesystem::path& filePath, std::uintmax_t& fileSize, std::filesystem::file_time_type& lastModTime, std::string& fileContent)
{
    std::ifstream in(inputFile, std::ios::binary);
    if (!in)
    {
        std::cerr << "Failed to open input file for deserialization." << std::endl;
        return;
    }

    // Read metadata
    std::string pathStr;
    std::getline(in, pathStr);
    filePath = pathStr;   // Assign string to path
    in >> fileSize;
    in.ignore(); // skip '\n'
    std::int64_t timeCount;
    in >> timeCount;
    in.ignore(); // skip '\n'
    lastModTime = std::filesystem::file_time_type(std::chrono::duration_cast<std::filesystem::file_time_type::duration>(std::chrono::nanoseconds(timeCount)));

    // Read actual file content
    fileContent.assign((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

    in.close();
}