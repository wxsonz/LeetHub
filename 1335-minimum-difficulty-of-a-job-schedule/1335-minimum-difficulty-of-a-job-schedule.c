int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

/*int minDifficulty(int* A, int n, int D) {
    if (n < D) return -1;
    
    int dp[n + 1];
    dp[n] = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = A[i] + dp[i + 1];
    }
    
    for (int d = 2; d <= D; d++) {
        for (int i = 0; i <= n - d; i++) {
            int maxd = 0;
            dp[i] = INT_MAX;

            for (int j = i; j <= n - d; j++) {
                maxd = max(maxd, A[j]);
                dp[i] = min(dp[i], maxd + dp[j + 1]);
            }
        }
    }
    
    return dp[0];
}*/

int minDifficulty(int* A, int n, int D) {
    if (n < D) return -1;

    int max_difficulty = INT_MAX / 2;
    int dp[n + 1][D + 1];

    for (int i = 0; i <= n; i++) {
        for (int d = 0; d <= D; d++) {
            dp[i][d] = max_difficulty;
        }
    }

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int d = 1; d <= D; d++) {
            int maxd = 0;

            for (int j = i - 1; j >= d - 1; j--) {
                maxd = max(maxd, A[j]);
                dp[i][d] = min(dp[i][d], maxd + dp[j][d - 1]);
            }
        }
    }

    return dp[n][D] != max_difficulty ? dp[n][D] : -1;
}