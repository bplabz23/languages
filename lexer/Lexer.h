/*
*		Name			:	Lexer.h
*
*		Author			:	Basil Moledina
*		Date			:	7/11/2024
*		Description		:	Lexical analyser, breaks up program into tokens 
*
*/


#include "Token.h"
#include <vector>
#include <string>
#include "CharList.h"








enum terminals
{
    WHITESPACE, LETTER, DIGIT, OPERATOR
};




std::vector<Token> lexer(std::string program); 



























