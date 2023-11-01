#ifndef MY_SERVER_
#define MY_SERVER_

// #include <yy00_my_main_server.hpp>
#include <main_header.hpp>

unsigned short toUnsShort(int num);

class Server
{
    protected:
        Socket serverSocket;

    public:
        Server() {}

        bool start(int port = 0)
        {
            if (!serverSocket.create()) 
            {
                // error
                return false;
            }
            if (!serverSocket.bind(port)) 
            {
                // error
                return false;
            }
            if (!serverSocket.listen()) 
            {
                // error
                return false;
            }
            return true;
        }

        int waitClientReq()
        {
            int clientSocket = serverSocket.accept();
            return clientSocket;
        }
        
        std::string getServerInfo()
        {
            std::string result = serverSocket.LocalEndpointInfo();
            return result;
        }

        ~Server() {}
};

// void printTask(int number);
void ftpTask(int clientSocket, const std::string& DTP_IpAddress);

class ServerTop : public Server
{
    private: 
    ThreadPool ThreadPool;

    public:
        ServerTop(unsigned int nbThread) : ThreadPool(nbThread) {}

        bool start(int port, const std::string& DTP_IpAddress)
        {
            if (!serverSocket.create()) 
            {
                // error
                return false;
            }
            if (!serverSocket.bind(port)) 
            {
                // error
                return false;
            }
            if (!serverSocket.listen()) 
            {
                // error
                return false;
            }

            while (true) 
            {
                int clientSocket = serverSocket.accept();
                std::cout << "Incoming client connected" << std::endl;
                ThreadPool.enqueue([clientSocket, DTP_IpAddress]() { ftpTask(clientSocket, DTP_IpAddress); });
            }

            return true;
        }
        ~ServerTop() {}
};

#endif