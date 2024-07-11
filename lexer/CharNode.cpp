/*
*
*		Name			:	CharNode.h
*
*		Author			:	Basil Moledina
*		Date			:	7/11/2024
*		Description		:   Holds a character and points to another CharNode
*
*/


#include "CharNode.h"



CharNode::CharNode()
{
    this->character = 0;
    this->next = nullptr;        
}


CharNode::CharNode(char c, CharNode* cNode)
{
    this->character = c;
    this->next = cNode;   
}


