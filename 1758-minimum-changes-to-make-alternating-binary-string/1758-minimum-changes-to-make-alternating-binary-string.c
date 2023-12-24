#define MIN(a,b) ((a) < (b) ? (a) : b)

int minOperations(char* s) {
    int sLen = strlen(s);
    int temp = 0;
    
    for (int i = 0; i < sLen; ++i)
        temp += s[i] - '0' != i % 2;
    
    return MIN(temp, sLen - temp);
}