#ifndef MY_FTP_CMD_
#define MY_FTP_CMD_

#include <main_header.hpp>
// #include <my_filesystem.hpp>

#define S_CS_150 "150 File status: ok\n\r"
#define S_CS_200 "200: Command okay.\n\r"
#define S_CS_220 "220: Service ready for new user.\r\n"
#define S_CS_221 "221 Goodbye.\r\n"
#define S_CS_207 "227EnteringPassiveMode("
#define S_CS_226 "226 transfer complete\n\r"
#define S_CS_230 "230: Anonymous access granted\n\r"
#define S_CS_502 "502: Command not implemented.\n\r"
#define S_CS_530 "530 Not logged in\n\r"
#define S_CS_550 "550: File not found.\r\n"

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
            clientPI.send(S_CS_230);
        }
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_ACC_PASS(SocketMov&& clientPI)
    {
        clientPI.send(S_CS_530);
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_ACC_ACCT()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_ACC_CWD (const std::string& token)
    {
        return dirtyCWD(token);
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_ACC_CDUP()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_ACC_SMNT()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    // std::string cmd_ACC_QUIT()
    // {
    //     std::cout << "PLACEHOLDER" << std::endl;
    // }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_ACC_REIN()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    // std::string cmd_ACC_EXIT()
    // {
    //     std::cout << "PLACEHOLDER" << std::endl;
    // }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    // TRANSFERT PARAMETER COMMANDS
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

    std::string cmd_TPC_PORT(SocketMov&& clientPI, std::string token)
    {
        clientPI.setActv();
        clientPI.RemoteEndpointInfo();
        std::pair<std::string, int> fullAddress = parsePORTResponse(token);
        clientPI.setExpectedIp(fullAddress.first);
        clientPI.setExpectedPort(fullAddress.second);
        std::string result = S_CS_200;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------

    std::string cmd_TPC_PASV(SocketMov&& clientPI)
    {
        clientPI.setPasv();
        clientPI.socketDTP.create();
        clientPI.socketDTP.bind();
        std::string LocalIpPort = clientPI.socketDTP.LocalEndpointInfo();
        std::string result = S_CS_207 + LocalIpPort + ")\n\r";
        std::cout << result << std::endl;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_TPC_TYPE()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_TPC_STRU()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_TPC_MODE()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    // FTP SERVICE COMMANDS


    bool fileExist(const std::string& token)
    {
        if (std::filesystem::exists(filePath))
        {
            return true;
        } else
        {
            return false;
        }
    }

    void actvTransfer(SocketMov&& clientPI, const std::string& token)
    {
        sleep(1);
        Socket socketDTP;
        socketDTP.create();
        std::string ipAddress = clientPI.getExpectedIp();
        int port = clientPI.getExpectedPort();
        socketDTP.connect(ipAddress, port);
        std::string file = prepareFile(token);
        socketDTP.send(file);
    }

    void pasvTranfer(SocketMov&& clientPI, const std::string& token)
    {
        clientPI.socketDTP.listen();
        int clientSocket = clientPI.socketDTP.accept();
        Socket DTPserver(clientSocket);
        std::string file = prepareFile(token);
        DTPserver.send(file);
        DTPserver.closeSocket();
    }


    std::string cmd_FCS_RETR(SocketMov&& clientPI, const std::string& token)
    {
        if (fileExist(const std::string token))
        {
            clientPI.send(S_CS_150);
            if (!clientPI.getPasv() && !clientPI.GetActv())
            {
                cmd_TPC_PASV(std::move(clientPI));
            }
            else if (clientPI.getPasv())
            {
                pasvTranfer(std::move(clientPI), token);
            }
            else if (clientPI.GetActv())
            {
                actvTransfer(std::move(clientPI), token);
            }
            std::string result = S_CS_226;
        }
        else 
        {
            std::string result = S_CS_550;
        }
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_STOR()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_STOU()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//--------------------------------------------------------------------- 
    std::string cmd_FCS_APPE()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_ALLO()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_REST()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_RFNR()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_RNTO()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_ABOR()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_DELE()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_RMD()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_MKD()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_PWD()
    {
        return dirtyPWD();
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_LIST()
    {
        return dirtyLS();
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_NLST()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_SITE()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_SYST()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_STAT()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_HELP()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmd_FCS_NOOP()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    ~cmdFTP() {}
};

#endif
