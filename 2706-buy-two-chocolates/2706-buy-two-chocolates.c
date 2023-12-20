int buyChoco(int* prices, int pricesSize, int money){
    
    int *min1 = (int*)malloc(sizeof(int));
    int *min2 = (int*)malloc(sizeof(int));
    int *minT = (int*)malloc(sizeof(int));
    
    *min1 = 100;
    *min2 = 100;
    
    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < *min1) {
            *min2 = *min1;
            *min1 = prices[i];
        } else if (prices[i] < *min2) {
            *min2 = prices[i];
        }
    }
    
    *minT = *min1 + *min2;
    
    if (*minT <= money) {
        free(min1);
        free(min2);
        int result = money - *minT;
        free(minT);
        return result;
    }
    
    free(min1);
    free(min2);
    free(minT);
    
    return money;
}