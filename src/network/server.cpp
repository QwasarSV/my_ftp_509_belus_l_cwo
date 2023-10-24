#include <yy00_my_main_server.hpp>

unsigned short toUnsShort(int num)
{
    unsigned short us = static_cast<unsigned short>(num);
    return us;
}

// int ServerTCP::ClientReq()
// {
//     sockaddr_in clientInfo;
//     int clientSocket;
//     socklen_t client_len = sizeof(clientInfo);
//     clientSocket= accept(socketFd, (struct sockaddr*)&clientInfo, &client_len);
//     if ( clientSocket == -1)
//     {
//         // error big bad ? 
//     }
//     return clientSocket;
// }

// int main()
// {
//     unsigned short us = toUnsShort(8080);
//     ServerTCP server(us);
//     while (true)
//     {
//         int clientSocket = server.ClientReq();
//         std::cout << "client connected" << std::endl;
//         close(clientSocket);
//     }

//     return 0;
// }