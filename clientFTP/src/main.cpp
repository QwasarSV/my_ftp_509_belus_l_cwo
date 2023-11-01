#include <main_header.hpp>


std::string createPortString(int local_port)
{
    int leftover_int = local_port % BYTE_MAX_PLUS_ONE;
    int mult_int = std::floor(local_port / BYTE_MAX_PLUS_ONE);
    std::string leftover_str = std::to_string(leftover_int);
    std::string mult_str = std::to_string(mult_int);
    std::string result = mult_str + "," + leftover_str ;
    return result;
}

std::pair<std::string, int> parsePASVResponse(const std::string& response)
{
    std::size_t startPos = response.find('(');
    std::size_t endPos = response.find(')');
    std::string data = response.substr(startPos + 1, endPos - startPos - 1);
    std::stringstream ss(data);
    std::string item;
    std::vector<int> values;
    while (std::getline(ss, item, ','))
    {
        values.push_back(std::stoi(item));
    }

    std::string ip = std::to_string(values[0]) + "." +
                     std::to_string(values[1]) + "." +
                     std::to_string(values[2]) + "." +
                     std::to_string(values[3]);

    int port = values[4] * 256 + values[5];
    return {ip, port};
}

std::string prepareACTVMessage(const std::string& token, std::string IpAddress)
{
    std::istringstream iss(token);
    std::string keyword;
    int value;
    iss >> keyword >> value;
    // int port = std::stoi(value);
    std::string port_str = createPortString(value);
    std::replace(IpAddress.begin(), IpAddress.end(), '.', ',');
    std::string result = keyword + " " + IpAddress + "," + port_str;
    return result;
}

int setDTP_PORT(const std::string& token)
{
    std::istringstream iss(token);
    std::string keyword;
    int value;
    iss >> keyword >> value;
    std::cout << "value"  << value <<std::endl;
    return value;
}


int main()
{
    const int PORT = 8080;
    const std::string HOST = "127.0.0.1";
    Client client;
    Client clientDTP;
    Socket activDTP;
    int DTP_PORT = 0;
    bool pasv = false;
    bool actv = false;
    bool loop = true;
    std::string line;
    std::pair<std::string, int> IpPort;
    if (client.connect(HOST, PORT))
    {
        std::string statusReq = client.receiveFrom();
        std::string resp;
        std::cout << "Status: " << statusReq << std::endl;
        while (loop && std::getline(std::cin, line))
        {
            if (!line.empty())
            {
                if (line.find("PORT") != std::string::npos)
                {
                    DTP_PORT = setDTP_PORT(line);
                    line = prepareACTVMessage(line, HOST);
                    std::cout << line <<std::endl;
                }
                // Reply back to the server
                client.sendTo(line);
                resp = client.receiveFrom();
                std::cout << resp << std::endl;
                if (resp.find("221") != std::string::npos)
                {
                    std::cout << "FTP server disconnected" << std::endl; 
                    loop = false;
                }
                if (resp.find("200") != std::string::npos)
                {
  
                    actv = true;
                }
                else if (resp.find("227") != std::string::npos)
                {
                    pasv = true;
                    IpPort = parsePASVResponse(resp);
                }
                else if (resp.find("150") != std::string::npos)
                {
                        if (pasv)
                        {
                            clientDTP.connect(IpPort.first, IpPort.second);
                            line.clear();
                            resp = clientDTP.receiveFrom();
                            std::cout << resp << std::endl;
                            resp.clear();
                            resp = client.receiveFrom();
                            std::cout << resp << std::endl;
                            // client.connect(HOST, PORT);
                        } 
                        else if (actv)
                        {
                        std::cout << "port"  << DTP_PORT <<std::endl;
                            Server DTP;
                            DTP.start(DTP_PORT);
                            // activDTP.create();
                            // activDTP.bindWithIp(HOST, DTP_PORT);
                            // std::cout << activDTP.LocalEndpointInfo() << std::endl;
                            // activDTP.listen();
                            int serverSocket = DTP.waitClientReq();
                            Socket ServerDTP(serverSocket);
                            resp = ServerDTP.receive();
                            std::cout << resp << std::endl;
                            // ServerDTP.closeSocket();
                            resp = client.receiveFrom();
                            std::cout << resp << std::endl;
                        }
                }
                line.clear();
            }
        }
    }
    else
    {
        std::cout << "big bad !!" << std::endl;
    }
}
