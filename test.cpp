
#include <iostream>
#include "CharList.h"

using namespace std;

int main()
{
    string greeting = "hello";
    cout << "Test string: " << greeting << endl << endl << endl;

    CharList l = CharList(greeting); 
    
    cout << "Add test: ";
    l.push('Z');
    l.insert('Z');

    cout << l.toString();
    
    cout << endl << endl << endl << "Delete Test: ";
    l.pop();
    l.dequeue();

    cout << l.toString();

    return 0;
}