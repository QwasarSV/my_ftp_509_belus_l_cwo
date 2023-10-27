#ifndef MY_FTP_
#define MY_FTP_


// #include <yy00_my_main_server.hpp>
#include <main_header.hpp>

extern  bool handleClientInput(std::string& resp, Lexer& lx, std::string& cmd, SocketMov&& clientPI);


class MyFTP
{
    private:
        
        std::string resp;
        bool stop = false;
    public:
    SocketMov clientPI;
        MyFTP(int clientSock = -1) : clientPI(SocketMov(clientSock))
        {
            if (clientSock == -1)
            {
                std::cerr << "Connection Failed" << std::endl;
            }
            // Socket connectionSocket(clientSock);
            clientPI.send("42069");
            Lexer lx;
            while (!stop)
            {
                std::string cmd = clientPI.receive();
                std::cout << cmd << std::endl;
                cmd.append(" EXIT");
                cmd.append(" ;;");
                stop = handleClientInput(resp, lx, cmd, std::move(clientPI));
                if (!stop)
                {
                    // prepared answer in HandleClientINput
                    std::cout << "sending answer" << std::endl;
                    // std::cout << resp << std::endl;
                    clientPI.send(resp);
                    resp.clear();
                }
                else
                {
                    clientPI.send("221 Goodbye.\r\n");
                }
            }
        }
        ~MyFTP() {}
};

#endif
