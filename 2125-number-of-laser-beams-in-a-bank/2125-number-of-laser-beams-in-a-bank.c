int numberOfBeams(char** bank, int bankSize) 
{
    int prev = 0, ans = 0;
    
    for (int i = 0; i < bankSize; i++) 
    {
        int count = 0;
        int len = strlen(bank[i]);
        
        for (int j = 0; j < len; j++) 
        {
            if (bank[i][j] == '1') count++;
        }
        
        if (count != 0) 
        {
            ans += (prev * count);
            prev = count;
        }
    }
    
    return ans;
}