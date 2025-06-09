/*
    Title: Power Function using Exponentiation by Squaring

    Problem Statement:
        - Implement a function to calculate b^e (b raised to power e), where:
            - b is a floating point number (base)
            - e is an integer (exponent)
        - Handle negative exponents correctly.

    Author: Siddhi
*/

#include <iostream>
using namespace std;

// Efficient power function (handles negative exponents)
float power(float b, int e) {
    if (e == 0) return 1;
    if (e < 0) return 1 / power(b, -e);

    float temp = power(b, e / 2);

    if (e % 2 == 0)
        return temp * temp;
    else
        return temp * temp * b;
}

int main() {
    float b = 0.2;
    int e = 5;

    cout << b << "^" << e << " = " << power(b, e) << endl;
    return 0;
}
