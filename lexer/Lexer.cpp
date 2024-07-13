/*
*		Name			:	Lexer.cpp
*
*		Author			:	Basil Moledina
*		Date			:	7/11/2024
*		Description		:	Lexical analyser, breaks up program into tokens 
*
*
*       Notes: Very top-down design, works from it's way from the very big picture all the way down to the small.
*/


#include "Lexer.h"
#include <iostream>
using namespace std;




// ****************************************** Token Recognition **********************************************************************

int get_token(CharList lex_buf);
bool is_token(CharList lex_buf);
bool is_whitespace(char c);
bool is_keyword(CharList l);
bool is_op(CharList l);
bool is_int(CharList l);
bool is_id(CharList l);

// ************************************************** Terminal recognition ***********************************************************

int classify_terminal(char c);
bool is_whitespace(char c);
bool is_letter(char c);
bool is_digit(char c);
bool is_operator(char c);






vector<Token> lexer(string program)
{
    
  

    vector<Token> token_buf = vector<Token>();      // Our token buffer
    CharList prgm_buf = CharList(program);          // Turn string into a list of characters
    
    cout << endl << "Program: \n";
    cout << prgm_buf.toString();
    cout << endl << endl;

    cout << "************* LEXER OUTPUT ***************" << endl; 

    // While we are not at the end of the file
    while( prgm_buf.start != nullptr )
    {
        
        CharList lex_buf = CharList();  // Make a new lexeme buffer for every lexeme in the program


        // Keep building lexeme until there are no more token matches or we are at the end of the file
        do 
        {

            lex_buf.push( prgm_buf.dequeue() );     // Load a char into the lexeme buffer
            //cout << lex_buf.toString() << '\t';
            //cout << prgm_buf.toString() << endl;
        }
        while( is_token(lex_buf) == true && prgm_buf.start != nullptr );


      
        if ( is_whitespace(lex_buf.start->character) )      // If this is white space, ignore it
        {
            continue;
        }

        else if (prgm_buf.start == nullptr)                 // If we are at the end of our program file
        {
            // Do nothing, just proceed to getting the token
        }

        else                                                
        {
            prgm_buf.insert( lex_buf.pop() );               // Otherwise, move back 1 token to restore the longest match
            //cout << lex_buf.toString() << '\t';
            //cout << prgm_buf.toString() << endl;
        }


        int token_type = get_token(lex_buf);                            // Get the token type of the lexeme
        token_buf.push_back( Token(lex_buf.toString(), token_type) );   // Add token to our list



    }



    // return the list of tokens
    return token_buf; 

}





// ****************************************************** Token Recognition *********************************************************


int get_token(CharList lex_buf)
{



    if (is_keyword(lex_buf))
    {
        return KEYWORD;
    }


    if (is_op(lex_buf))
    {
        switch(lex_buf.start->character)
        {
            case '=':
                return EQU;
            case '+':
                return ADD;
            case '-':
                return SUB;
            case '*':
                return MUL;
            case '/':
                return DIV;
            default:
                return -1;      // error
        }
    }


    if (is_int(lex_buf))
    {
        return INT;
    }

    if (is_id(lex_buf))
    {
        return ID;
    }
    

    return -1;               // otherwise, return an error

}


bool is_token(CharList lex_buf)
{

    int match = 0;                          // Number of tokens this lexeme matches
    string lexeme = lex_buf.toString();
    
    if ( is_whitespace(lex_buf.start->character) )
    {
        return false;
    }

    if (is_keyword(lex_buf))
    {
        match++;
    }


    if (is_op(lex_buf))
    {
        match++;
    }


    if (is_int(lex_buf))
    {
        match++;
    }

    if (is_id(lex_buf))
    {
        match++;
    }
    

    if (match > 0)              // if our lexeme matched at least 1 token
    {
        return true;            // Return true
    }

    return false;               // otherwise, return false


}


// KEYWORD, EQU, ADD, SUB, MUL, DIV, INT, ID

bool is_keyword(CharList l)
{
    string str = l.toString();              // Convert to string
    
    vector<string> keywords = vector<string>();     // Some nasty setup (that ought to be stored in a file)
    keywords.push_back("if");
    keywords.push_back("then");

    for(string k : keywords)                // For all possible keywords
    {
        if ( k.compare(str) == 0 )          // if the lex_buffer matches keyword k
        {
            return true;                    // Return true
        }

    }
    return false;                           // else, return false

}




bool is_op(CharList l)
{

    // If there is more than 1 terminal in the lexeme, this is not an operator token
    if (l.toString().size() > 1)
    {
        return false;
    }

    char terminal = l.start->character; 

    switch(terminal)
    {
        case '=':
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
    }

    return false;
}




bool is_int(CharList l)
{
    CharNode *ptr = l.start; // Iterate through entire character list
    while(ptr != nullptr)
    {        
        if ( !is_digit( ptr->character ) )          // check if each terminal is a digit
        {
            return false;                           // If not, return false                   
        }

        ptr = ptr->next;                            // move to next termnial
    }

    return true;                                    // else, return true

}



bool is_id(CharList l)
{
    CharNode *ptr = l.start;                        // Iterate through entire terminal list
    while(ptr != nullptr)
    {        
        if ( !is_letter( ptr->character ) )         // check if each terminal is a letter
        {
            return false;                           // If not, return false                   
        }

        ptr = ptr->next;                            // move to next termnial
    }

    return true;                                    // else, return true  

}


// ************************************************** Terminal recognition ***********************************************************



int classify_terminal(char c)
{

    if (is_whitespace(c))
    {
        return WHITESPACE;
    }

    else if (is_letter(c))
    {
        return LETTER;
    }

    else if (is_digit(c))
    {
        return DIGIT;
    }

    else if (is_operator(c))
    {
        return OPERATOR;
    }

    else 
    {
        return -1;
    }

}



bool is_whitespace(char c)
{
    switch(c)
    {
        case ' ':
        case '\t':
        case '\n':
        return true;
    }

    // else
    return false;

}




bool is_letter(char c)
{

    // [65-90] [97-122]
    if ( c >= 65 && c <= 90)
    {
        return true;
    }

    if( c >= 97 && c <= 122 )
    {
        return true;
    }


    // else
    return false;
}




bool is_digit(char c)
{
    if (c >= 48 && c <= 57)
    {
        return true;
    }

    //else 
    return false;

}



bool is_operator(char c)
{

    switch (c)
    {
        case '=':
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
            break;
    }

    // else

    return false;

}





















