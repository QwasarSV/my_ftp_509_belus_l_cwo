#ifndef MY_SOCKET_CPP_
#define MY_SOCKET_CPP_

#include <my_main_server.hpp>


class Socket
{
    private:
        int socketFd;

    public:
        Socket() :sockfd(-1) {}

        bool create()
        {
            socketFd = socket(AF_INET, SOCK_STREAM, 0);
            if (socketFd != -1)
            {
                return true;
            } 
            else
            {
                return false
            }
        }

        bool bind(unsigned short port)
        {
            struct sockaddr_in servInfo;
            servInfo.sin_family = AF_INET;
            servInfo.sin_port = htons(port);
            servInfo.sin_addr.s_addr = INADDR_ANY;
            memset(servInfo.sin_zero, 0, sizeof(servInfo.sin_zero));
            if (bind(socketFd, (struct sockaddr*)&servInfo, sizeof(servInfo)) == -1)
            {
                return false; 
            }
            return true;
        }
        
        bool listen()
        {
            if (listen(socketFd, 1) == -1)
            {
                return false;
            }
            std::cout << "server listening on port " << port << std::endl;
            return true
        }

        int accept()
        {
            sockaddr_in clientInfo;
            int clientSocket;
            socklen_t client_len = sizeof(clientInfo);
            clientSocket = accept(socketFd, (struct sockaddr*)&clientInfo, &client_len);
            return clientSocket;
        }

        bool connect(const std::string &serverIp = "127.0.0.1", unsigned short port = 0)
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

            if (connect(socketFd, (struct sockaddr *)&clientInfo, sizeof(clientInfo)) == -1)
            {
                // error big bad ?
                return false;
            }
            return true;
        }

        ssize_t send(const std::string &msg)
        {
            int len = msg.length();
            ssize_t byteSent = 0;
            byteSent += send(socketFd, &len, 0);
            byteSent += send(socketFd, msg.c_str(), msg.length(), 0);
            return byteSent
        }

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

        
        std::string receive()
        {
            int len = 0;
            recv(socketfd, &len, sizeof(length), 0);
            // Allocate buffer and receive the actual message
            char* buff = new char[len];
            recv(socketfd, buf, len, 0);
            std::string msg(buf, len);
            delete[] buf;
            return msg;
        }

        void closeSocket()
        {
            close(socketFd);
        }

        ~Socket()
        {
            if (socket != -1)
            {
                close();
            }
        }
};

#endif