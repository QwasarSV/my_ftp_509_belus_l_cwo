#ifndef MY_SERVER_
#define MY_SERVER_

#include <yy00_my_main_server.hpp>

unsigned short toUnsShort(int num);

class Server
{
    private:
        Socket ServerSocket;

    public:
        Server() {}

        bool start(int port)
        {
            if (!ServerSocket.create()) 
            {
                // error
                return false;
            }
            if (ServerSocket.bind(port)) 
            {
                // error
                return false;
            }
            if (ServerSocket.listen()) 
            {
                // error
                return false;
            }

            return true;
        }

        int waitClientReq()
        {
            int clientSocket = ServerSocket.accept();
            return clientSocket;
        }
        ~Server() {}
};

#endif