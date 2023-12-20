int buyChoco(int* prices, int pricesSize, int money){
    int min1, min2;
    // min1 < min2
    
    if (prices[0] < prices[1]) {
        min1 = prices[0];
        min2 = prices[1];
    }
    else {
        min1 = prices[1];
        min2 = prices[0];
    }
    
    for (int i = 2; i < pricesSize; i++) {
        if (prices[i] < min1) {
            min2 = min1;
            min1 = prices[i];
        } else if (prices[i] < min2) {
            min2 = prices[i];
        }
    }
    
    int minT = min1 + min2;
    
    if (minT <= money) {
        return money - (minT);
    }
    
    return money;
}