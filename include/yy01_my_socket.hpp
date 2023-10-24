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
        // ssize_t receive(char* buffer, size_t len)
        // {
        //     ssize_t byteReceived = recv(socketfd, buffer, len, 0);;
        //     return byteReceived
        // }
        // std::string receive()
        // {
        //     char buffer[RW_SIZE];
        //     std::string answer;
        //     size_t byteRead = 0;
        //     while ((byteRead = read(socketFd, buffer, RW_SIZE)))
        //     {
        //         answer.append(buffer, byteRead);
        //     }
        //     return answer;
        // }
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