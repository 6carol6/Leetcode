class Solution {
private:
    int dp[10000];
public:
    int numTrees(int n) {
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= n; i++){
            if(i < 3){
                dp[i] = i; continue;
            }
            for(int j = 1; j <= i; j++){
                dp[i] += dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};
