#include <memory.h>
class Solution {
private:
    bool check(int i, int j, int n, int m){
        if(i>=0 && i<n){
            if(j>=0 && j<m){
                return true;
            }
        }
        return false;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[101][101];
        memset(dp, 0, sizeof(dp));
        int n = obstacleGrid.size(), m = 0;
        if(n != 0) m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 0)
            dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(obstacleGrid[i][j] == 1) continue;
                if(check(i, j-1, n, m) && obstacleGrid[i][j-1] == 0){
                    dp[i][j] += dp[i][j-1];
                }
                if(check(i-1, j, n, m) && obstacleGrid[i-1][j] == 0){
                    dp[i][j] += dp[i-1][j];
                }
            }
        }
        return dp[n-1][m-1];
    }
};