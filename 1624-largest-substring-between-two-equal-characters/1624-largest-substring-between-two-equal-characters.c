#define CHAR_RANGE 26
#define max(a, b) (a > b ? a : b)

int maxLengthBetweenEqualCharacters(char* s) 
{   
    int firstIndex[CHAR_RANGE];
    
    for (int i = 0; i < CHAR_RANGE; i++) 
    {
        firstIndex[i] = -1;
    }
    
    int ans = -1;
    int length = strlen(s);
    
    for (int i = 0; i < length; i++) 
    {
        int index = s[i] - 'a';
        
        if (firstIndex[index] != -1) 
        {
            ans = max(ans, i - firstIndex[index] - 1);
        } 
        else 
        {
            firstIndex[index] = i;
        }
    }

    return ans;
}