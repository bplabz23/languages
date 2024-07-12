/*
*
*		Name			:	Lexeme.h
*
*		Author			:	Basil Moledina
*		Date			:	7/10/2024
*		Description		:	Header file
*
*
*/


#include "Token.h"


Token::Token(std::string lexeme, int token_type)
{
    this->lexeme = lexeme;
    this->token_type = token_type;
}



Token::Token()
{
    this->lexeme = "";
    this->token_type = -1;
}


std::string Token::toString()
{
    std::string str = "Lexeme: ";
    str += this->lexeme;
    str += "\t";
    str += "Token: ";

    //KEYWORD, EQU, ADD, SUB, MUL, DIV, INT, ID
    switch(this->token_type)
    {
        case KEYWORD:
            str += "KEYWORD";
            break;

        case EQU:
            str += "EQU";
            break;

        case ADD:
            str += "ADD";
            break;

        case SUB:
            str += "SUB";
            break;

        case MUL:
            str += "MUL";
            break;

        case DIV:
            str += "DIV";
            break;

        case INT:
            str += "INT";
            break;

        case ID:
            str += "ID";
            break;

    }


    str += "\n";

    return str;
}