
#include <iostream>
#include "Lexer.h"

using namespace std;

int main()
{

    string prgm = "x = 420";

    vector<Token> lexedProgram = vector<Token>();

    lexedProgram = lexer(prgm);

    // print out results
    for (Token t : lexedProgram)
    {
        cout << t.toString();
    }


}