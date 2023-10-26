#ifndef MY_FTP_CMD_
#define MY_FTP_CMD_

#include <my_filesystem.hpp>
// #include <yy00_my_main_server.hpp>

class cmdFTP
{
    public:
    // ACCESS CONTROL COMMANDS
    std::string cmd_ACC_USER()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_ACC_PASS()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_ACC_ACCT()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_ACC_CWD ()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_ACC_CDUP()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_ACC_SMNT()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_ACC_QUIT()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_ACC_REIN()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_ACC_EXIT()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }


    // TRANSFERT PARAMETER COMMANDS
    std::string cmd_FPC_PORT()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_FPC_PASV()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_FPC_TYPE()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_FPC_STRU()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }
    std::string cmd_FPC_MODE()
    {
        std::cout << "PLACEHOLDER" << std::endl;
    }


    // FTP SERVICE COMMANDS
    std::string cmd_FCS_RETR()
    {
        std::cout << "PLACEHOLDER" << std::endl;
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
};

#endif
