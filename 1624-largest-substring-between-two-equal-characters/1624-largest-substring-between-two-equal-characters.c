int maxLengthBetweenEqualCharacters(char* s) {
    int firstIndex[128];
    
    for (int i = 0; i < 128; i++) {
        firstIndex[i] = -1;
    }
    
    int ans = -1;
    int length = strlen(s);
    
    for (int i = 0; i < length; i++) {
        if (firstIndex[s[i]] != -1) {
            ans = (ans > i - firstIndex[s[i]] - 1) ? ans : i - firstIndex[s[i]] - 1;
        } else {
            firstIndex[s[i]] = i;
        }
    }

    return ans;
}