//============================================================================
// Name        : LambdaParametersAndReturnTypes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void testGreet(void (*greet)(string)) {
    greet("Bob");
}

void runDivide(double (*divide)(double a, double b)) {
    auto rval = divide(9, 3);
    cout << rval << endl;
}

int main()
{
    auto pGreet = [](string name) { cout << "Hello " << name << endl;};
    
    pGreet("Mike");
    
    testGreet(pGreet);
    
    auto pDivide = [](double a, double b) -> double {
        if(b == 0.0) {
            return 0;
        }
        return a/b;
    };
    
    cout << pDivide(10.0, 5.0) << endl;
    cout << pDivide(10.0, 0.0) << endl;
    
    runDivide(pDivide);
    
    return 0;
}
