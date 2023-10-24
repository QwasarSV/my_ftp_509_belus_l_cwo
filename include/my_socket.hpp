#ifndef MY_SOCKET_CPP_
#define MY_SOCKET_CPP_

#include <my_main_server.hpp>

class Socket
{
    private:
    int socketFd;

    public:
        Socket(int domain, int type, int protocol)
        {
            socketFd = socket(domain, type, protocol);
        }

        std::string ReceiveMessage();

        void writeMessage(const std::string& message);

        int getSocket() const;

        ~Socket()
        {
            close(socketFd);
        }
};

#endif