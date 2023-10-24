#ifndef MY_SOCKET_
#define MY_SOCKET_

#include <yy00_my_main_server.hpp>


class Socket
{
    private:
        int socketFd;

    public:
        Socket() :socketFd(-1) {}

        bool create();
        bool bind(unsigned short port);
        bool listen();
        int accept();
        bool connect(const std::string &serverIp = "127.0.0.1", unsigned short port = 0);
        ssize_t send(const std::string &msg);
        std::string receive();
        void closeSocket();
        ~Socket()
        {
            if (socketFd != -1)
            {
                closeSocket();
            }
        }
};

#endif