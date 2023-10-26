#ifndef MY_FTP_
#define MY_FTP_


#include <yy00_my_main_server.hpp>

class MyFTP
{
    private:
        std::string answer;
        bool stop = false;
    public:
        MyFTP(int clientSock = -1)
        {
            if (clientSock == -1)
            {
                std::cerr << "Connection Failed" << std::endl;
            }
            Socket connectionSocket(clientSock);
            connectionSocket.send("42069");
            Lexer lx;
            while (!stop)
            {
                std::string cmd = connectionSocket.receive();
                std::cout << cmd << std::endl;
                cmd.append(" EXIT");
                cmd.append(" ;;");
                stop = handleClientInput(lx, cmd);
                if (!stop)
                {
                    // prepared answer in HandleClientINput
                    std::cout << "sending answer" << std::endl;
                    connectionSocket.send("answer");
                }
                else
                {
                    connectionSocket.send("221 Goodbye.\r\n");
                }
            }
        }
        ~MyFTP() {}
};

#endif
