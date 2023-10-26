#include <main_header.cpp>

#include <iostream>
#include <filesystem>

int dirtyLS()
{
    std::string path = ".";  // Current directory

    try {
        for (const auto &entry : std::filesystem::directory_iterator(path)) {
            std::cout << entry.path() << std::endl;
        }
    }
    catch (std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}