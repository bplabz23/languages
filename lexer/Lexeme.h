/*
*
*		Name			:	Lexeme.h
*
*		Author			:	Basil Moledina
*		Date			:	7/10/2024
*		Description		:	Header file
*
*
*		Notes:
*					Lexeme	=  A group of characters
*					Token	=  The type of lexeme (is this group of characters a name, keyword, int etc?)
*
*/


// Imports
#include <string>



struct Token
{
	// Data
	std::string lexeme;
	std::string token_type;
	
	// Functions
	Token(std::string lexeme, std::string token_type);
};



