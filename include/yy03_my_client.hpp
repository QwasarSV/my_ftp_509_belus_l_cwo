#ifndef MY_CLIENT_
#define MY_CLIENT_

#include <yy00_my_main_server.hpp>

unsigned short toUnsShort(int num);

class Client
{
    private:
        Socket clientSocket;

    public:
        Client() {}

        bool connect()
        {
            if (!clientSocket.create())
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
        
        std::string receiveFrom()
        {
            std::string msg = clientSocket.receive();
            return msg;
        }

    ~Client() {}
};

#endif