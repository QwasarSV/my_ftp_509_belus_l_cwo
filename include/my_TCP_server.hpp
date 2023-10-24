#ifndef MY_TCP_SERVER_
#define MY_TCP_SERVER_

#include <my_main_server.hpp>

unsigned short toUnsShort(int num);


class ServerTCP
{
    private:
    int socketFd;

    public:
        ServerTCP(unsigned short port)
        {
            socketFd = socket(AF_INET, SOCK_STREAM, 0);
            if (socketFd == -1)
            {
                // error big bad ?
            }

            struct sockaddr_in servInfo;
            servInfo.sin_family = AF_INET;
            servInfo.sin_port = htons(port);
            servInfo.sin_addr.s_addr = INADDR_ANY;
            memset(servInfo.sin_zero, 0, sizeof(servInfo.sin_zero));

            if (bind(socketFd, (struct sockaddr*)&servInfo, sizeof(servInfo)) == -1)
            {
                // error big bad ? 
            }

            listen(socketFd, 1);
            std::cout << "server listening on port " << port << std::endl;
        }

        int ClientReq();

        ~ServerTCP()
        {
            close(socketFd);
        }
};

#endif