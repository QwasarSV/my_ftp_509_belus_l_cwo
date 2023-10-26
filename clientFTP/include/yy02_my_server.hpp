#ifndef MY_SERVER_
#define MY_SERVER_

#include <yy00_my_main_server.hpp>

unsigned short toUnsShort(int num);

class Server
{
    protected:
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
            if (!ServerSocket.bind(port)) 
            {
                // error
                return false;
            }
            if (!ServerSocket.listen()) 
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

// void printTask(int number);
void ftpTask(int clientSocket);

class ServerTop : public Server
{
    private: 
    ThreadPool ThreadPool;

    public:
        ServerTop(unsigned int nbThread) : ThreadPool(nbThread) {}

        bool start(int port)
        {
            if (!ServerSocket.create()) 
            {
                // error
                return false;
            }
            if (!ServerSocket.bind(port)) 
            {
                // error
                return false;
            }
            if (!ServerSocket.listen()) 
            {
                // error
                return false;
            }

            while (true) 
            {
                int clientSocket = ServerSocket.accept();
                ThreadPool.enqueue([clientSocket]() { ftpTask(clientSocket); });
            }

            return true;
        }
        ~ServerTop() {}
};

// int main() {
//     ThreadPool pool(2); // 2 worker threads

//     for (int i = 0; i < 5; ++i) {
//         pool.enqueue([i]() { printTask(i); });
//     }

//     std::this_thread::sleep_for(std::chrono::seconds(2)); // let threads process tasks
//     return 0;
// }

#endif