// #include <my_filesystem.hpp>
#include <main_header.hpp>


std::string dirtyLS()
{
    std::string path = ".";  // Current directory
    std::string result;
    try
    {
        result = std::filesystem::current_path();
        result.append(": \n");
        for (const auto &entry : std::filesystem::directory_iterator(path))
        {
            result.append(entry.path());
            result.append("\n");
        }
    }
    catch (std::filesystem::filesystem_error& error)
    {
        result = "Error: ";
        result.append(error.what());
    }
    return result;
}

std::string dirtyPWD()
{
    std::string result;
    try
    {
        result = "Current working directory: ";
        result.append(std::filesystem::current_path());
    }
    catch (std::filesystem::filesystem_error& error)
    {
        result = "Error: ";
        result.append(error.what());
    }
    return result;
}

std::string dirtyCWD(const std::string& pathToNewDir)
{
    std::string result;
    try
    {
        std::filesystem::current_path(pathToNewDir);
        result = "New working directory: ";
        result.append(std::filesystem::current_path());
    }
    catch (std::filesystem::filesystem_error& error)
    {
        result = "Error: ";
        result.append(error.what());
    }
    return result;
}