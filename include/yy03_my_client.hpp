#ifndef MY_CLIENT_
#define MY_CLIENT_

#include <my_main_server.hpp>

unsigned short toUnsShort(int num);

class Client
{
    private:
        Socket clientSocket;

    public:
        Client() {}

        bool connect()
        {
            if (!clientSocket.Create())
            {
                return false;
            }
            if (!clientSocket.connect())
            {
                return false;
            }
            return true;
        }

        void sendTo(const std::string &msg)
        {
            clientSocket.send(msg);
        }
        
        void receiveFrom(const std::string &msg)
        {
            

        }

    ~Client() {}
};

#endif