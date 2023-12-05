#include <math.h>

bool isThree(int n) {
    
    if (n < 4) return 0;
    
    int sqrt_n = sqrt(n);
    if (sqrt_n * sqrt_n != n) return 0;
    
    for (int i = 2; i * i <= sqrt_n; i++) 
    {
        if (n % i == 0) return 0;
    }
    
    return 1;
}