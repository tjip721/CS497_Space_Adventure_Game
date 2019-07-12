#include <iostream>
#include <algorithm>
#include <sstream>
#include "Parser.hpp"

Parser::Parser(std::string i)
{
    input = i;
    Parser::inputToLowerCase();
    Parser::tokenizeInput();
}

void Parser::inputToLowerCase()
{
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
}

void Parser::tokenizeInput()
{
    std::stringstream inputSS(input);
    std::string temp;
    while(std::getline(inputSS, temp, ' '))
    {
        tokens.push_back(temp);
    }
}

void Parser::printTokens()
{
    for(int i = 0; i < tokens.size(); i++)
    {
        std::cout << tokens[i] << std::endl;
    }
}

void Parser::printString(){
    std::cout << input << std::endl;
}
