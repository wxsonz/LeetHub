int lengthOfLongestSubstring(char* s) {
    
    int maxLength = 0;
    int charIndex[256];

    for (int i = 0; i < 256; ++i) {
        charIndex[i] = -1;
    }

    int start = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (charIndex[s[i]] >= start) {
            start = charIndex[s[i]] + 1;
        }
        charIndex[s[i]] = i;
        int length = i - start + 1;
        if (length > maxLength) {
            maxLength = length;
        }
    }

    return maxLength;
    
}