/*
#include <math.h>

bool isThree(int n) {
    
    // number with 3 divisor always has 1, prime number, itself
    
    // skip to 4
    if (n < 4) return 0;
    
    // do a squre root
    int sqrt_n = sqrt(n);
    
    // if sqaure root is not a whole number then skip
    if (sqrt_n * sqrt_n != n) return 0;
    
    // check if the square root number is also a prime
    for (int i = 2; i * i <= sqrt_n; i++) 
    {
        if (n % i == 0) return 0;
    }
    
    return 1;
}
*/

// manual labour yahooo
// O(n) BABYYYYYYYY
bool isThree(int n) {
    int squares[] = {4, 9, 25, 49, 121, 169, 289, 361, 529, 841, 961, 1369, 1681, 1849, 2209, 2809, 3481, 3721, 4489, 5041, 5329, 6241, 6889, 7921, 9409};
    
    int numSquares = sizeof(squares) / sizeof(squares[0]);

    for (int i = 0; i < numSquares; ++i) {
        if (n == squares[i]) {
            return 1;
        }
    }

    return 0;
}