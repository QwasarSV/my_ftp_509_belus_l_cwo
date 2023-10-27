#ifndef MY_SOCKET_
#define MY_SOCKET_

// #include <yy00_my_main_server.hpp>
#include <main_header.hpp>

#include <utility> 
class Socket
{
    private:
        int socketFd;

    public:
        Socket(int socketFd = -1) : socketFd(socketFd) {}

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

class SocketMov : public Socket
{
    private:
        int socketFd;

    public:
        SocketMov(int fd) : Socket(fd) {}
        SocketMov(SocketMov&& other) noexcept : socketFd(std::move(other.socketFd))
        {
            other.socketFd = -1;  // or some invalid value
        }

        SocketMov& operator=(SocketMov&& other) noexcept
        {
            if (this != &other) 
            {
                closeSocket();
                socketFd = other.socketFd;
                other.socketFd = -1;
            }
            return *this;
        }
        ~SocketMov()
        {
            if (socketFd != -1)
            {
                closeSocket();
            }
        }
};

#endif