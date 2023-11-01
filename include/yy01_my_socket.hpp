#ifndef MY_SOCKET_
#define MY_SOCKET_

// #include <yy00_my_main_server.hpp>
#include <main_header.hpp>
#include <utility>
#define BYTE_MAX_PLUS_ONE 256

class Socket
{
    private:
        int socketFd;
        std::string ExpectedIP;

    public:
        Socket(int socketFd = -1) : socketFd(socketFd) {}

        bool create();
        bool bind(unsigned short port = 0);
        bool listen();
        int accept();
        bool connect(const std::string &serverIp = "127.0.0.1", unsigned short port = 0);
        ssize_t send(const std::string &msg);
        std::string receive();

        void setExpectedIP(std::string str)
        {
            ExpectedIP = str;
        }
        std::string createPortString(int local_port)
        {
            int leftover_int = local_port % BYTE_MAX_PLUS_ONE;
            int mult_int = std::floor(local_port / BYTE_MAX_PLUS_ONE);
            std::string leftover_str = std::to_string(leftover_int);
            std::string mult_str = std::to_string(mult_int);
            std::string result = mult_str + "," + leftover_str ;
            return result;
        }

        std::string LocalEndpointInfo()
        {
            struct sockaddr_in local_address;
            socklen_t addr_length = sizeof(local_address);
            if (getsockname(socketFd, (struct sockaddr*)&local_address, &addr_length) == -1)
            {
                //  big bad
            }
            else
            {
                char* local_ip = inet_ntoa(local_address.sin_addr);
                int local_port = ntohs(local_address.sin_port);

                std::string IpAddress = local_ip;
                if (IpAddress == "0.0.0.0")
                {
                    IpAddress = ExpectedIP;
                }
                std::replace(IpAddress.begin(), IpAddress.end(), '.', ','); 
                std::string localPort = createPortString(local_port);
                std::string result = IpAddress + "," + localPort;
                return result;
            }
        }

        std::string RemoteEndpointInfo()
        {
            struct sockaddr_in remote_address;
            socklen_t addr_length = sizeof(remote_address);
            if (getpeername(socketFd, (struct sockaddr*)&remote_address, &addr_length) == -1)
            {
                // big bad
            } 
            else
            {
                char* remote_ip = inet_ntoa(remote_address.sin_addr);
                std::string IpAddress = remote_ip;
                return IpAddress;
            }
        }

        void closeSocket();

        ~Socket()
        {
            if (socketFd != -1)
            {
                closeSocket();
            }
        }
};

class SocketMov : public Socket
{
    private:
        int socketFd;
        int expectedPort;
        std::string expectedIP;
        bool pasv = true;
        bool actv = false;
    public:
        Socket socketDTP;
        SocketMov(int fd) : Socket(fd) {}
        SocketMov(SocketMov&& other) noexcept : socketFd(std::move(other.socketFd))
        {
            other.socketFd = -1;  // or some invalid value
        }

        SocketMov& operator=(SocketMov&& other) noexcept
        {
            if (this != &other) 
            {
                closeSocket();
                socketFd = other.socketFd;
                other.socketFd = -1;
            }
            return *this;
        }

        void setPasv()
        {
            pasv = true;
            actv = false;
        }

        void setActv()
        {
            pasv = false;
            actv = true;
        }

        void setExpectedPort(int port)
        {
            expectedPort = port;
        }
        
        void setExpectedIp(std::string IpAddress)
        {
            expectedIP = IpAddress;
        }

        bool getPasv()
        {
            return pasv;
        }

        bool GetActv()
        {
            return actv;
        }

        int getExpectedPort()
        {
            return expectedPort;
        }

        std::string getExpectedIp()
        {
            return expectedIP;
        }

        ~SocketMov()
        {
            if (socketFd != -1)
            {
                closeSocket();
            }
        }
};

#endif