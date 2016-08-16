#include <memory.h>
class Solution {
private:
    const int MAX = 2147483647;
    const int MAXN = 10000;
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[MAXN];
        for(int i = 0; i < MAXN; i++){
            dp[i] = MAX;
        }
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            int min = MAX;
            for(int j = 0; j < coins.size(); j++){
                if(coins[j] <= i){
                    if(dp[i-coins[j]] < min) min = dp[i-coins[j]];
                }
            }
            if(min != MAX)
                dp[i] = (min+1)<dp[i]?(min+1):dp[i];
        }
        if(dp[amount] == MAX) return -1;
        return dp[amount];
    }
};