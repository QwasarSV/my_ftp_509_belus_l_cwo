#include <zz00_my_main_lang.hpp>

void handleFileInput(Lexer& lx, const std::string& token)
{
    lx.tokeniseFile(token);
    lx.printVec();
    PairVec_t instructions = lx.getInstrVec();
    launch(instructions);
}

bool handleClientInput(std::string& resp, Lexer& lx, std::string& cmd)
{
    bool result = false;
    try 
    {
        lx.parseCmd(cmd);
        // lx.printVec();
        PairVec_t instructions = lx.getInstrVec();
        result = launchFTP(resp, instructions);
        lx.clear();
    }
    catch (const std::exception& error)
    {
        lx.clear();
        std::cerr << error.what() << std::endl;
    }
    catch (...)
    {
        lx.clear();
        std::cerr << "Unknown error: " << std::endl;
    }
    return result;
}

void handleStandardInput(Lexer& lx)
{
    bool result = true;
    while (result)
    {
        try
        {
            lx.parseLine();
            lx.printVec();
            PairVec_t instructions = lx.getInstrVec();
            result = launch(instructions);
            lx.clear();
        }
        catch (const std::exception& error)
        {
            lx.clear();
            std::cerr << error.what() << std::endl;
        }
        catch (...)
        {
            lx.clear();
            std::cerr << "Unknown error: " << std::endl;
        }
    }
}

void Exec::execMethod(const std::string& methodName)
{
    std::cout << "method name: " << methodName << std::endl;
    if (funcPtrMap.find(methodName) != funcPtrMap.end())
    {
        (this->*funcPtrMap[methodName])();
    }
    else
    {
        throw ExecutionError("INVALID METHOD DESIGNATION\n");
    }
}

void Exec::execMethodFTP(std::string& resp, const std::string& methodName)
{
    std::cout << "method name: " << methodName << std::endl;
    if (funcPtrMap.find(methodName) != funcPtrMap.end())
    {
        resp = (this->*funcPtrMap[methodName])();
    }
    else
    {
        throw ExecutionError("INVALID METHOD DESIGNATION\n");
    }
}

int launch(const PairVec_t& instructions)
{
    Exec ex;
    for (const TokPair_t instruction : instructions)
    {
        if (instruction.first == S_ACC_USER)
        {
            const ValPair_t& value = instruction.second.value();
            // ex.method(value.first, value.second.value());
        }
        else if (instruction.first == S_ACC_QUIT)
        {
            std::cout << "Disconnecting client" << std::endl;
            return EXIT_INSTRUCTION;
        }
        else if (instruction.first == S_ACC_EXIT)
        {
            return NEXT_INSTRUCTION;
        }

        else if (!instruction.first.empty())
        {
            ex.execMethod(instruction.first);
        }
        else
        {
            // ex.clear();
            return EXIT_FAILURE;
        }
    }
    throw ExecutionError("MISSING EXIT INSTRUCTION");
    return EXIT_FAILURE;
}

int launchFTP(std::string& resp, const PairVec_t& instructions)
{
    Exec ex;
    for (const TokPair_t instruction : instructions)
    {
        if (instruction.first == S_ACC_USER)
        {
            const ValPair_t& value = instruction.second.value();
            // ex.method(value.first, value.second.value());
        }
        else if (instruction.first == S_ACC_QUIT)
        {
            std::cout << "Disconnecting client" << std::endl;
            return EXIT_INSTRUCTION;
        }
        else if (instruction.first == S_ACC_EXIT)
        {
            return NEXT_INSTRUCTION;
        }

        else if (!instruction.first.empty())
        {
            ex.execMethodFTP(resp, instruction.first);
        }
        else
        {
            // ex.clear();
            return EXIT_FAILURE;
        }
    }
    throw ExecutionError("MISSING EXIT INSTRUCTION");
    return EXIT_FAILURE;
}
