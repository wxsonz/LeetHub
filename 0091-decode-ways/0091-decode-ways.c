int numDecodings(char* s) {
    
    if (s[0] == '0') return 0;
    
    int n = strlen(s);
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        
        int one_digit = s[i - 1] - '0';
        int two_digits = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
        
        if (one_digit >= 1 && one_digit <= 9) 
            dp[i] += dp[i - 1];
        
        if (two_digits >= 10 && two_digits <= 26) 
            dp[i] += dp[i - 2];

    }
    
    return dp[n];
}