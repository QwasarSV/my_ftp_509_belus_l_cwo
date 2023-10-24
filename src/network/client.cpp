#include <my_main_server.hpp>

class ClientTCP
{
    private:
    int socketFd;

    public:
        ClientTCP(const std::string &serverIp = "127.0.0.1", unsigned short port = 0)
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
            }

            if (connect(socketFd, (struct sockaddr *)&clientInfo, sizeof(clientInfo)) == -1)
            {
                // error big bad ? 
            }
        }

        int ClientReq();

        ~ClientTCP()
        {
            close(socketFd);
        }
};