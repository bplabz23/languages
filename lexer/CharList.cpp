/*
*
*		Name			:	CharList.cpp
*
*		Author			:	Basil Moledina
*		Date			:	7/11/2024
*		Description		:   Linked data structure that holds a characters and provides additional operations
*
*/


#include "CharList.h"




CharList::CharList()
{
    this->start = nullptr;
    this->end = nullptr;
}





// (note this problem is very similar to switching values of two vars using a temp)
CharList::CharList(std::string s)
{

    int length = s.size();
    CharNode *prev_ptr, *next_ptr;

    // For each char, put it in a node
    for (int i = 0; i < length; i++)   
    {


        // If this is the start of the list
        if (i == 0)
        {
            this->start = new CharNode();           // build a node at the start ptr
            this->start->character = s.at(i);       // Copy the character to the node
            prev_ptr = this->start;                 // Since its been made, previously-made node becomes the one at start.
        }


        // Else  
        else 
        {
            next_ptr = new CharNode();      // Build a node at next 
            prev_ptr->next = next_ptr;      // Get the previous node to point to it
            prev_ptr = next_ptr;            // Now that the next node has been made, program considers it "previously made"
        }


    }

    // end of the list is whatever is the most previously-made node.
    this->end = prev_ptr;

} 




/*
void CharList::push(char c);          // Back 
char CharList::pop();                
    
void CharList::insert(char c);        // Front
char CharList::dequeue();             
*/




std::string CharList::toString();




