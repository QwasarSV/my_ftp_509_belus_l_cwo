#ifndef MY_FTP_CMD_
#define MY_FTP_CMD_

#include <main_header.hpp>
// #include <my_filesystem.hpp>
class cmdFTP
{
    // protected:
    // Socket clientPI;

    public:
    cmdFTP() {}
    // ACCESS CONTROL COMMANDS
    std::string cmd_ACC_USER(SocketMov&& clientPI, const std::string& token)
    {
        if (token == "Anonymous")
        {
            clientPI.send("230 Anonymous access granted");
        }
    }

    std::string cmd_ACC_PASS(SocketMov&& clientPI)
    {
        clientPI.send("530 Not logged in");
    }

    std::string cmd_ACC_ACCT()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }

    std::string cmd_ACC_CWD (const std::string& token)
    {
        return dirtyCWD(token);
    }

    std::string cmd_ACC_CDUP()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }

    std::string cmd_ACC_SMNT()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }

    // std::string cmd_ACC_QUIT()
    // {
    //     std::cout << "PLACEHOLDER" << std::endl;
    // }

    std::string cmd_ACC_REIN()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }

    // std::string cmd_ACC_EXIT()
    // {
    //     std::cout << "PLACEHOLDER" << std::endl;
    // }


    std::pair<std::string, int> parsePORTResponse(const std::string& response)
    {
        std::stringstream ss(response);
        std::string item;
        std::vector<int> values;
        int tmp = 0;
        while (std::getline(ss, item, ','))
        {
            tmp = std::stoi(item);
            values.push_back(tmp);
        }

        std::string ip = std::to_string(values[0]) + "." +
                         std::to_string(values[1]) + "." +
                         std::to_string(values[2]) + "." +
                         std::to_string(values[3]);
        // std::string ip = "127.0.0.1";
        int port = values[4] * 256 + values[5];
        // int port = 1233;

        return {ip, port};
    }


    // TRANSFERT PARAMETER COMMANDS
    std::string cmd_TPC_PORT(SocketMov&& clientPI, std::string token)
    {
        clientPI.setActv();
        clientPI.RemoteEndpointInfo();
        std::pair<std::string, int> fullAddress = parsePORTResponse(token);
        clientPI.setExpectedIp(fullAddress.first);
        clientPI.setExpectedPort(fullAddress.second);
        std::string result = "200";
        return result;
    }

    // std::string createPortString(const std::string& port)
    // {
    //     int leftover_int = number % BYTE_MAX_PLUS_ONE;
    //     int mult_int = std::floor(number / BYTE_MAX_PLUS_ONE);
        
    //     std::string leftover_str = std::to_string(leftover_int);
    //     std::string mult_str = std::to_string(mult_int);
    //     std::string result = leftover_str + "," + mult_str;
    //     return result;
    // }

    std::string cmd_TPC_PASV(SocketMov&& clientPI)
    {
        clientPI.setPasv();
        clientPI.socketDTP.create();
        clientPI.socketDTP.bind();
        std::string LocalIpPort = clientPI.socketDTP.LocalEndpointInfo();
        std::string result = "227EnteringPassiveMode(" + LocalIpPort + ")\n\r";
        std::cout << result << std::endl;
        return result;
    }

    std::string cmd_TPC_TYPE()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }

    std::string cmd_TPC_STRU()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }

    std::string cmd_TPC_MODE()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }


    // FTP SERVICE COMMANDS
    std::string cmd_FCS_RETR(SocketMov&& clientPI, const std::string& token)
    {
        clientPI.send("150 File status: ok\n\r");
        if (!clientPI.getPasv() && !clientPI.GetActv())
        {
            cmd_TPC_PASV(std::move(clientPI));
        }
        else if (clientPI.getPasv())
        {
            clientPI.socketDTP.listen();
            int clientSocket = clientPI.socketDTP.accept();
            Socket DTPserver(clientSocket);
            std::string file = Serialize(token);
            DTPserver.send(file);
            DTPserver.closeSocket();
        }
        else if (clientPI.GetActv())
        {
            Socket socketDTP;
            socketDTP.create();
            // clientPI.socketDTP.create();
            std::string ipAddress = clientPI.getExpectedIp();
            int port = clientPI.getExpectedPort();
            std::cout << "ipaddr |" << ipAddress <<"|"<< std::endl;
            std::cout << "port " << port << std::endl;
            socketDTP.connect(ipAddress, port);
            // clientPI.socketDTP.connect("127.0.0.1", 12311);
            std::string file = Serialize(token);
            socketDTP.send(file);
        }
        // std::string file = Serialize(token);
        // clientPI.socketDTP.send(file);
        // clientPI.socketDTP.closeSocket();
        std::string result = "226 transfer complete\n\r";
        return result;
        // return file;
    }

    std::string cmd_FCS_STOR()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
   
    std::string cmd_FCS_STOU()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
 
    std::string cmd_FCS_APPE()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }

    std::string cmd_FCS_ALLO()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
   
    std::string cmd_FCS_REST()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
  
    std::string cmd_FCS_RFNR()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
  
    std::string cmd_FCS_RNTO()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
 
    std::string cmd_FCS_ABOR()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
  
    std::string cmd_FCS_DELE()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }

    std::string cmd_FCS_RMD()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }

    std::string cmd_FCS_MKD()
    {
        std::string result = "PLACEHOLDER";
        std::cout << "PLACEHOLDER" << std::endl;
        return result;
    }
    std::string cmd_FCS_PWD()
    {
        return dirtyPWD();
    }      
    std::string cmd_FCS_LIST()
    {
        return dirtyLS();
    }
    std::string cmd_FCS_NLST()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_FCS_SITE()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_FCS_SYST()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_FCS_STAT()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_FCS_HELP()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_FCS_NOOP()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    ~cmdFTP() {}
};

#endif
