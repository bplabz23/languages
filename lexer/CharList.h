/*
*
*		Name			:	CharList.h
*
*		Author			:	Basil Moledina
*		Date			:	7/11/2024
*		Description		:   Linked data structure that holds a characters and provides additional operations
*
*/

#include <string>
#include "CharNode.h"



struct CharList
{

    CharNode start;
    CharNode end;


    CharList();
    CharList(std::string s); 


    void push(char c);          // Back 
    char pop();                
    
    void insert(char c);        // Front
    char dequeue();             

    std::string toString();
};


