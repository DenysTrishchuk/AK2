#include <iostream>
#include <string.h>
#include "calculator.h"


using namespace std;

Calculator calc;
double a = 7.7;
double b = 3.3;


int main() { 
    std::cout << "Add result:\n";
    std::cout << "a + b = " << calc.Add(a, b) << std::endl;  
    return 0;
}
