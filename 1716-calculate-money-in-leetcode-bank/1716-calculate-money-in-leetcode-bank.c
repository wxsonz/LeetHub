int totalMoney(int n) {
    
    // ah yes totally worth of malloc
    int *total =(int *)malloc(sizeof(int));
    int *floor = (int *)malloc(sizeof(int));
    int *ceil = (int *)malloc(sizeof(int));
    
    // loop
    // f + f+1 + f+2 + f+3 + f+4  ...
    // keep adding to total
    
    // and from example 
    //... + 7) + (2 + 3...
    //... + 8) + (3 + 4...
    
    // it is always +-5 
    // 7 - 5 = 2 or 2 + 5 = 7
    
    // f - 6 to compensate the if (f > c)
    
    // using example and its like
    // ...+ 7) + ((+ 8 - 6) + 3...
    // ...+ 8) + ((+ 9 - 6) + 4...
    
    *total = 0;
    *floor = 1;
    *ceil = 7;
    
    for (int i = 0; i < n; i++)
    {
        *total += *floor;
        
        (*floor)++;
        
        if (*floor > *ceil)
        {
            (*ceil)++;
            (*floor) = (*ceil) - 6;
        }
    }
    
    n = *total;
    
    free(total);
    free(floor);
    free(ceil);
    
    return n;
}