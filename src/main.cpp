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


//getoptobj : 



// #include <stdlib.h>
// #include <my_unistd.h>
// #include <stdlib.h>

int main(int argc, char** argv)
{


    // std::vector<std::string> tokens;

    // for (int i = 0; i < argc; ++i) {
    //     tokens.push_back(std::string(argv[i]));
    // }

    // MyGeOpt* GetOptObj = new MyGeOpt;  // Constructor called here
    // GetOptObj->FlagParser(tokens);
    // delete GetOptObj;  // Destructor called here


    ServerTop server(2);
    server.start(8080);
    


    


    // const int PORT = 8080;
    // const std::string HOST = "127.0.0.1";
    
    // // Start the server in a separate thread
    // std::thread serverThread([&]() {
    //     std::cout << "thread started" << std::endl;
    //     Server server;
    //     if (server.start(PORT)) {
    //         int clientSock = server.waitClientReq();
    //         if (clientSock != -1) {
    //             std::cout << "Client connected!" << std::endl;
                
    //             // For simplicity, just send a message to the client
    //             Socket connectionSocket(clientSock);
    //             connectionSocket.send("Hello from server!");
    //             // char buffer[1024];
    //             std::string msg = connectionSocket.receive();
    //             std::cout << msg << std::endl;
    //             // ssize_t bytesReceived = connectionSocket.receive(buffer, sizeof(buffer));
    //             // std::cout << "Server received: " << std::string(buffer, bytesReceived) << std::endl;
    //         }
    //     }
    // });
    
    // // Give the server some time to start up
    // std::this_thread::sleep_for(std::chrono::seconds(2));

    // // Connect a client to the server
    // Client client;
    // if (client.connect(HOST, PORT)) {
    //     std::string serverMessage = client.receiveFrom();
    //     std::cout << "Client received: " << serverMessage << std::endl;

    //     // Reply back to the server
    //     client.sendTo("Hello back from client!");
    // }
    // else
    // {
    //     std::cout << "big bad !!" << std::endl;
    // }
    
    // serverThread.join();

    return EXIT_SUCCESS;
}