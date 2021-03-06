#include <memory.h>

class Solution {
private:
    int dp[1000];
    int max(int a, int b){
        return a>b?a:b;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size()-1; i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        int tmp = dp[nums.size()-2];
        memset(dp, 0, sizeof(dp));
        dp[0] = 0; dp[1] = nums[1];
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return max(tmp, dp[nums.size()-1]);
    }
};