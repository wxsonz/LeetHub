int minCost(char * colors, int* neededTime, int neededTimeSize){
    
    int res = neededTime[0];
    int max_cost = neededTime[0];

    for (int i = 1; i < neededTimeSize; ++i) {
        
        if (colors[i] != colors[i - 1]) {
            res -= max_cost;
            max_cost = 0;
        }
        
        res += neededTime[i];
        
        if (neededTime[i] > max_cost) max_cost = neededTime[i];
        
    }
    return res - max_cost;
    
}