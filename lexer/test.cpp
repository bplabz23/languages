
#include <iostream>
#include "Lexer.h"

using namespace std;

int main()
{

    string prgm = "x = 420\n";
    prgm += "if a = 7\n";
    prgm += "then x = x + 7";

    vector<Token> lexedProgram = vector<Token>();

    lexedProgram = lexer(prgm);

    // print out results
    for (Token t : lexedProgram)
    {
        cout << t.toString();
    }


}