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
        std::string DTP_IpAddress;
        MyFTP(int clientSock = -1, const std::string& DTP_server = "") : clientPI(SocketMov(clientSock))
        {
            clientPI.socketDTP.setExpectedIP(DTP_server);
            if (clientSock == -1)
            {
                std::cerr << "Connection Failed" << std::endl;
            }
            clientPI.send("220");
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
                    std::cout << "sending answer" << std::endl;
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
