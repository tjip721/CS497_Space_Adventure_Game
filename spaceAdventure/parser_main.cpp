#include "Parser.hpp"

int main()
{
    Parser testParser("A TEST STRING");
    testParser.printString();
    testParser.printTokens();
    return 0;
}
