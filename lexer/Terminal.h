/*
*
*		Name			:	Terminal.h
*
*		Author			:	Basil Moledina
*		Date			:	7/11/2024
*		Description		:	Header file
*
*
*/


// Imports
#include <string>




enum symbol_classes 
{
    DIGIT, LETTER, EQUOP
};



struct Terminal
{
    char symbol;
    int symbol_class;
};




