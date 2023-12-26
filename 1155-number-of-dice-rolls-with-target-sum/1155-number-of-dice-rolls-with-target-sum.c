#define max(a,b) ((a > b) ? a : b)
#define MOD 1000000007
int memo[31][1001];

int dp(int d, int target, int f) {
    
    if (d == 0) {
        return (target > 0) ? 0 : 1;
    }
    
    if (memo[d][target] != -1) {
        return memo[d][target];
    }
    
    int to_return = 0;
    
    for (int k = max(0, target - f); k < target; k++) {
        to_return = (to_return + dp(d - 1, k, f)) % MOD;
    }
    
    memo[d][target] = to_return;
    return to_return;
    
}

int numRollsToTarget(int d, int f, int target) {
    
    for (int i = 0; i <= d; i++) {
        for (int j = 0; j <= target; j++) {
            memo[i][j] = -1;
        }
    }
    
    return dp(d, target, f);
}