#include <yy00_my_main_server.hpp>

unsigned short toUnsShort(int num)
{
    unsigned short us = static_cast<unsigned short>(num);
    return us;
}

bool Socket::create()
{
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd != -1)
    {
        return true;
    } 
    else
    {
        return false;
    }
}

bool Socket::bind(unsigned short port)
{
    struct sockaddr_in servInfo;
    servInfo.sin_family = AF_INET;
    servInfo.sin_port = htons(port);
    servInfo.sin_addr.s_addr = INADDR_ANY;
    memset(servInfo.sin_zero, 0, sizeof(servInfo.sin_zero));
    if (::bind(socketFd, (struct sockaddr*)&servInfo, sizeof(servInfo)) != -1)
    {
        return true; 
    }
    return false;
}

bool Socket::bindWithIp(const std::string &ipAddress, unsigned short port)
{
    struct sockaddr_in servInfo;
    servInfo.sin_family = AF_INET;
    servInfo.sin_port = htons(port);
    servInfo.sin_addr.s_addr = inet_addr(ipAddress.c_str());
    memset(servInfo.sin_zero, 0, sizeof(servInfo.sin_zero));
    if (::bind(socketFd, (struct sockaddr*)&servInfo, sizeof(servInfo)) != -1)
    {
        return true; 
    }
    return false;
}

bool Socket::listen()
{
    if (::listen(socketFd, 1) == -1)
    {
        return false;
    }
    std::cout << "server listening "  << std::endl;
    return true;
}

int Socket::accept()
{
    sockaddr_in clientInfo;
    int clientSocket;
    socklen_t client_len = sizeof(clientInfo);
    clientSocket = ::accept(socketFd, (struct sockaddr*)&clientInfo, &client_len);
    return clientSocket;
}

bool Socket::connect(const std::string &serverIp, unsigned short port)
{
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd == -1)
    {
        // error big bad ?
    }
    struct sockaddr_in clientInfo;
    clientInfo.sin_family = AF_INET;
    clientInfo.sin_port = htons(port);
    memset(clientInfo.sin_zero, 0, sizeof(clientInfo.sin_zero));
    if (inet_pton(AF_INET, serverIp.c_str(), &clientInfo.sin_addr) <= 0)
    {
        // error big bad ?
        return false; 
    }
    if (::connect(socketFd, (struct sockaddr *)&clientInfo, sizeof(clientInfo)) == -1)
    {
        // error big bad ?
        return false;
    }
    return true;
}

ssize_t Socket::send(const std::string &msg)
{
    int len = msg.length();
    ssize_t byteSent = 0;
    byteSent += ::send(socketFd, &len, sizeof(len), 0);
    byteSent += ::send(socketFd, msg.c_str(), msg.length(), 0);
    return byteSent;
}



std::string Socket::receive()
{
    int len = 0;
    recv(socketFd, &len, sizeof(len), 0);
    // Allocate buffer and receive the actual message
    char* buf = new char[len];
    recv(socketFd, buf, len, 0);
    std::string msg(buf, len);
    delete[] buf;
    return msg;
}

// ssize_t socket::receive(char* buffer, size_t len)
// {
//     ssize_t byteReceived = recv(socketfd, buffer, len, 0);;
//     return byteReceived
// }
// std::string socket::receive()
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

void Socket::closeSocket()
{
    close(socketFd);
}


// std::string Socket::ReceiveMessage()
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

// void Socket::writeMessage(const std::string& message)
// {
//     ssize_t byteSent = send(socketFd, message.c_str(), message.length(), 0);
//     if (byteSent == -1)
//     {
//          // error big bad ? 
//     }
// }

// int Socket::getSocket() const
// {
//     return socketFd;
// }

