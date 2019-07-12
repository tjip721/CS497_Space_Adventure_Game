#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

class Parser
{
    private:
        std::string input;
        std::vector<std::string> tokens;

        void inputToLowerCase();
        void tokenizeInput();
    public:
        Parser(std::string i);
        void printString();
        void printTokens();
};

#endif // PARSER_H
