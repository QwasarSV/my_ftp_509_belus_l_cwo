#include <main_header.hpp>


// bool tokenize(std::string &str, const char& delimiter)
// {
//     std::string token;
//     std::istringstream tokenStream(str);
//     while (std::getline(tokenStream, token, delimiter))
//     {
//             MyGeOpt* GetOptObj = new MyGeOpt;  // Constructor called here
//             GetOptObj.FlagParser(tokens);
//             delete GetOptObj;  // Destructor called here
//     }
//     return true;
// }

// void parseLine()
// {
//     std::string line;
//     bool loop = true;
//     while (loop && std::getline(*inputPtr, line))
//     {
//         loop = tokenize(line, CHAR_SPACE);
//     }
//     if (inputPtr == &std::cin && inputPtr->eof()) 
//     {
//         std::cout << "EOF (Ctrl+D) detected." << std::endl;
//     }
     
// }

// my_getopt_t*    getopt_ptr  = NULL;
//             getopt_ptr = malloc(sizeof(my_getopt_t));
//             init_getopt(getopt_ptr, VALID_ARG);
//             flag_parser(cmd_count, tokens, VALID_ARG, getopt_ptr);
//             free_opt(cmd_count, tokens, getopt_ptr);

#include <stdlib.h>
#include <my_unistd.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    std::vector<std::string> tokens;

    for (int i = 0; i < argc; ++i) {
        tokens.push_back(std::string(argv[i]));
    }

    MyGeOpt* GetOptObj = new MyGeOpt;  // Constructor called here
    GetOptObj->FlagParser(tokens);
    delete GetOptObj;  // Destructor called here



    return EXIT_SUCCESS;
}