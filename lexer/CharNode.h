/*
*
*		Name			:	CharNode.h
*
*		Author			:	Basil Moledina
*		Date			:	7/11/2024
*		Description		:   Holds a character and points to another CharNode
*
*/


struct CharNode
{

    char character;
    CharNode* next;

    CharNode();
    CharNode(char c, CharNode* cNode);

};