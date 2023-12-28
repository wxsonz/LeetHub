#define MAX_LENGTH 110
#define INF 9999

#define min(a, b) (a < b ? a : b)

int getLengthOfOptimalCompression(char *s, int k) {
    
    int n = strlen(s);
    int dp[MAX_LENGTH][MAX_LENGTH];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = INF;
        }
    }
    
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            int cnt = 0, del = 0;
            for (int l = i; l >= 1; l--) {
                if (s[l - 1] == s[i - 1]) {
                    cnt++;
                } else {
                    del++;
                }
                
                if (j - del >= 0) {
                    dp[i][j] = min(dp[i][j],
                        dp[l - 1][j - del] + 1 + (cnt >= 100 ? 3 : cnt >= 10 ? 2 : cnt >= 2 ? 1 : 0));
                }
            }
            
            if (j > 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
        }
    }
    
    return dp[n][k];
}