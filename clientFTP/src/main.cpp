#include <main_header.hpp>

int main()
{
    const int PORT = 8080;
    const std::string HOST = "127.0.0.1";
    Client client;
    bool loop = true;
    std::string line;

    if (client.connect(HOST, PORT))
    {
        std::string statusReq = client.receiveFrom();
        std::string resp;
        std::cout << "Status: " << statusReq << std::endl;
        while (loop && std::getline(std::cin, line))
        {
            // Reply back to the server
            client.sendTo(line);
            resp = client.receiveFrom();
            if (resp.find("221") != std::string::npos)
            {
                std::cout << "FTP server disconnected" << std::endl; 
                loop = false;
            }
            std::cout << resp <<std::endl;
            line.clear();
        }
    }
    else
    {
        std::cout << "big bad !!" << std::endl;
    }
}

