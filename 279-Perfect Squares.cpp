#include <memory.h>
class Solution {
private:
    int min(int a, int b){
        return a<b?a:b;
    }
public:
    int numSquares(int n) {
        int dp[10001];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 1; i<=n; i++){
            int j = 1;
            while(j*j <= i){
                dp[i] = min(dp[i], dp[i-j*j]+1);
                j++;
            }
        }
        return dp[n];
    }
};