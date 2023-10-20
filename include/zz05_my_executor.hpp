#ifndef MY_EXECUTOR_HEADER_
#define MY_EXECUTOR_HEADER_

#include <zz00_my_main_lang.hpp>

/*
    class Exec
        input:  instructions vector 
            Execute the various methods processed through the lexer lifecyclel
        output: EXIT_STATUS
*/

// : public MyClass
class Exec
{
    private:
    // MyClass obj;
        // typedef void (MyStack::*ClassMethod)(void);
        typedef void (*ClassMethod)(void);
        std::unordered_map<std::string, ClassMethod> funcPtrMap;

    public:
        Exec()
        {
            // funcPtrMap[S_CAT_TOK]   = &MyCLASS::TOK;
        }
    void execMethod(const std::string& methodName);
};

int launch(const PairVec_t& instructions);

void handleFileInput(Lexer& lx, const std::string& token);
void handleStandardInput(Lexer& lx);

#endif
