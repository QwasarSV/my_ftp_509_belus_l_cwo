#ifndef MY_LANG_PARAM_
#define MY_LANG_PARAM_

#include <zz00_my_main_lang.hpp>
/*
    BNF notation : 
        <program> ::= {<line>} [";;"]
        <line> ::= <instruction> "#" | <comment> "#" | "#"
        <instruction> ::= <keyword> [<value>]
        <keyword> ::= "USER" | "PASS" | "ACCT" | "CDUP" | "SMNT" | "REIN" | "QUIT" | "PORT" | "PASV" | "TYPE" |
        "STRU"| "MODE" | "RETR" | "STOR" | "STOU" | "APPE" | "ALLO" | "REST" | "RFNR" | "RNOT" |
        "ABOR"| "DELE" | "RMD" | "MKD" | "PWD" | "NLST" | "SITE" | "SYST" | "STAT" | "HELP" |
        "NOOP" |
        <value> ::= <value_type> "(" <number> ")"
        <value_type> ::= "int8" | "int16" | "int32" | "float" | "double"
        <number> ::= {<digit>} ["." {<digit>}]
        <digit> ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
        <comment> ::= ";" {<any_character_except_newline_or_semicolon>} [";"]
*/
#define EXIT_INSTRUCTION        1

#define CHAR_SPACE              ' '
#define CHAR_OPARENTHESIS       '('
#define CHAR_CPARENTHESIS       ')'
#define CHAR_DECPOINT           '.'

#define S_CATEGORY_CHARACTERS   "characters"
#define S_CATEGORY_ACC          "AccessControlCommands"
#define S_CATEGORY_TPC          "TransfertParameterCommands"
#define S_CATEGORY_FSC          "FTPservicesCommands"
#define S_CATEGORY_DIGITS       "digits"


#define S_CHARACTERS_NEWLINE    "#"
#define S_CHARACTERS_COMMENT    ";"
#define S_CHARACTERS_DECPOINT   "."
#define S_CHARACTERS_ENDINSTR   ";;"


// ACCESS CONTROL COMMANDS
#define S_ACC_USER              "USER"
#define S_ACC_PASS              "PASS"
#define S_ACC_ACCT              "ACCT"
#define S_ACC_CWD               "CWD"
#define S_ACC_CDUP              "CDUP"
#define S_ACC_SMNT              "SMNT"
#define S_ACC_REIN              "REIN"
#define S_ACC_QUIT              "QUIT"


// TRANSFERT PARAMETER COMMANDS
#define S_FPC_PORT              "PORT"
#define S_FPC_PASV              "PASV"
#define S_FPC_TYPE              "TYPE"
#define S_FPC_STRU              "STRU"
#define S_FPC_MODE              "MODE"


// FTP SERVICE COMMANDS
#define S_FCS_RETR              "RETR"
#define S_FCS_STOR              "STOR"
#define S_FCS_STOU              "STOU"
#define S_FCS_APPE              "APPE"
#define S_FCS_ALLO              "ALLO"
#define S_FCS_REST              "REST"
#define S_FCS_RFNR              "RFNR"
#define S_FCS_RNTO              "RNOT"
#define S_FCS_ABOR              "ABOR"
#define S_FCS_DELE              "DELE"
#define S_FCS_RMD               "RMD"
#define S_FCS_MKD               "MKD"
#define S_FCS_PWD               "PWD"
#define S_FCS_LIST              "LIST"
#define S_FCS_NLST              "NLST"
#define S_FCS_SITE              "SITE"
#define S_FCS_SYST              "SYST"
#define S_FCS_STAT              "STAT"
#define S_FCS_HELP              "HELP"
#define S_FCS_NOOP              "NOOP"


#define S_DIGIT_0               "0"
#define S_DIGIT_1               "1"
#define S_DIGIT_2               "2"
#define S_DIGIT_3               "3"
#define S_DIGIT_4               "4"
#define S_DIGIT_5               "5"
#define S_DIGIT_6               "6"
#define S_DIGIT_7               "7"
#define S_DIGIT_8               "8"
#define S_DIGIT_9               "9"

using SharedToken_t     = std::shared_ptr<std::string>;

using TokVec_t          = std::vector<std::string>;
using SharedTokVec_t    = std::vector<SharedToken_t>;

using ValPair_t         = std::pair<std::string, std::optional<std::string>>;
using TokPair_t         = std::pair<std::string, std::optional<ValPair_t>>;
using PairVec_t         = std::vector<TokPair_t>;

using SetVariant_t = std::variant<
    // std::unordered_set<char>,
    std::unordered_set<std::string>
>;

/*
    class InstrPair
    input: nil
    Provide a structure to receive tokens and organise them in the form of an instruction
    rely on a double pair instr is pair<str, pair<str, str>>
    output instruction
*/


class InstrPair
{
    private:
        bool        readyStatus;
        TokPair_t   instr;
    public:

        InstrPair() : readyStatus(false){}

        void first(std::string keyword)
        {
            instr.first = keyword;
        }

        void second(ValPair_t value)
        {
            instr.second = value;
        }

        void third(std::string digit)
        {
            instr.second->second = digit;
        }

        const TokPair_t getPair() const
        {
            return instr;
        }

        ~InstrPair(){}
};

#endif
