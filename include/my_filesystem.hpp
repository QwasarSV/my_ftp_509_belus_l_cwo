#ifndef MY_FILESYSTEM_
#define MY_FILESYSTEM_

#include <iostream>
#include <fstream>
#include <filesystem>

// Directory Management
std::string dirtyLS();
std::string dirtyPWD();
std::string dirtyCWD(const std::string& pathToNewDir);

// Serialization 

unsigned int GetFileSize(std::string filename);
std::filesystem::directory_entry getFileInfo();
std::string Serialize(const std::filesystem::path& filePath);
void deserialize(const std::string& inputFile, std::filesystem::path& filePath, std::uintmax_t& fileSize, std::filesystem::file_time_type& lastModTime, std::string& fileContent);

#endif