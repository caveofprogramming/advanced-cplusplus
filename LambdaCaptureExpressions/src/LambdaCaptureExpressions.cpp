//============================================================================
// Name        : LambdaCaptureExpressions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

int main() {
    int one = 1;
    int two = 2;
    int three = 3;
    
    // Capture one and two by value
    [one, two](){ cout << one << ", " << two << endl; }();
    
    // Capture all local variables by value.
    [=](){ cout << one << ", " << two << endl; }();
    
    // Default capture all local variables by value, but three by reference.
    [=, &three](){ three = 7; cout << one << ", " << two << endl; }();
    cout << three << endl;
    
    // Default capture all local variables by reference.
    [&](){ three = 7; two = 8; cout << one << ", " << two << endl; }();
    cout << two << endl;
    
    // Default capture all local variables by reference but two and three by value.
    [&, two, three](){ one = 100;  cout << one << ", " << two << endl; }();
    cout << one << endl;
    
    return 0;
}
