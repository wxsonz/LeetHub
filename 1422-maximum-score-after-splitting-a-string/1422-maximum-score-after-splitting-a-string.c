int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxScore(char* s) {
    
    int o = 0; int z = 0; int best = -2147483648;
    
    int i = 0;
    
    while (s[i + 1] != '\0') {
        if (s[i] == '1') 
            o++;
        else 
            z++;
        
        best = max(best, z - o);
        i++;
    }
    
    if (s[i] == '1')
        o++;
    
    return best + o;
    
}