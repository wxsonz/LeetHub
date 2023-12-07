/*

used testcase to find actual minimum of problem

and many hours of a manual monke analysis from testcase

concluded to just use prime factorization
but sum them up instead of multiply

1000 = 2 x 2 x 2 x 5 x 5 x 5
1000 = 2 + 2 + 2 + 5 + 5 + 5
1000 = 6 + 15
1000 = 21

*/

int minSteps(int n) {
    
    // malloc yahooooo
    int *sum = (int*)malloc(sizeof(int));
    int *factor = (int*)malloc(sizeof(int));
    
    *sum = 0;
    *factor = 2;
    
    // essentially doing 
    // 1000 % 2 == 0 ? yes then sum + 2 and 1000 / 2
    // 500 % 2...
    // 125 % 2 == 0 ? nope now the 2 is ++
    // 125 % 3...
    
    while (n > 1)
    {
        while (n % *factor == 0)
        {
            *sum += *factor;
            n /= *factor;
        }
        
        (*factor)++;
    }
    
    n = *sum;
    
    free(sum);
    free(factor);
    
    return n;
}