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
#include <iostream>


CharList::CharList()
{
    this->start = nullptr;
    this->end = nullptr;
}





// (note this problem is very similar to switching values of two vars using a temp)

// Copy a string into linked nodes
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
            next_ptr->character = s.at(i);  // Copy the i-th char into the node
            prev_ptr->next = next_ptr;      // Get the previous node to point to it
            prev_ptr = next_ptr;            // Now that the next node has been made, program considers it "previously made"
        }


    }

    // end of the list is whatever is the most previously-made node.
    this->end = prev_ptr;

} 





void CharList::push(char c)
{
    // if CharList has members
    if (start != nullptr)
    {
        CharNode *temp = new CharNode();       // Put c in a node
        temp->character = c; 

        end->next = temp;                // Get last node to point to it    
        end = temp;                      // Make it the new end
    }

    // else if CharList is empty
    else     
    {
        CharNode *temp = new CharNode();
        temp->character = c;
        start = temp;
        end = temp;
    }


} 
                      



char CharList::pop()
{
    char c = end->character;            // Copy the character we are about to pop off
    CharNode *temp = start;             // Point to the start of the list

    while(temp->next->next != nullptr)  // Traverse the list until we get to the node right before the final node
    {
        temp = temp->next;
    }

    delete end;             // Delete the end node
    end = temp;             // Make temp the new end of the list
    end->next = nullptr;    // Delete reference to the old end node

    return c;
}                





void CharList::insert(char c)
{
    CharNode *temp = new CharNode();    // Create new node
    temp->character = c;                // Copy c to it
    temp->next = start;                 // Make it point to the start of the list
    start = temp;                       // Officially mark it as the new start of the list

}




char CharList::dequeue()
{
    char c = start->character;          // Copy the value of the starting node
    CharNode *temp, *delete_me;                     // Point to the node after start
    
    temp = start->next;
    delete_me = start;

    delete delete_me;                   // delete the start node
    start = temp;                       // set start to the temporary reference node
    return c;
    
}             





std::string CharList::toString()
{

    std::string str = "";           // Create an empty buffer
    CharNode* temp = this->start;   // Sort of a node buffer, initially points to beginning of list.


    // Iterate through list
    while (temp != nullptr)
    {
        
        str.push_back( temp->character );   // Get currently pointed-at character, add to buffer
        temp = temp->next;                  // Point at next character
    }

    return str;
}




