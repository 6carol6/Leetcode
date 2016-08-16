#include <memory.h>
class Solution {
private:
    int min(int a, int b){
        return a<b?a:b;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int dp[1000][1000];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++){
            dp[i][0] = dp[i-1][0]+triangle[i][0];
            for(int j = 1; j < triangle[i-1].size(); j++){
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
            dp[i][triangle[i-1].size()] = dp[i-1][triangle[i-1].size()-1] + triangle[i][triangle[i-1].size()];
        }
        int ans = 2147483647;
        for(int i = 0; i < triangle[triangle.size()-1].size(); i++){
            if(dp[triangle.size()-1][i] < ans){
                ans = dp[triangle.size()-1][i];
            }
        }
        return ans;
    }
};