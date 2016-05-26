#include <memory.h>

class Solution {
private:
    int nums[1001][1001];
    int min(int a, int b){
        return a<b?a:b;
    }
    bool isBorder(int x, int y, int n, int m){
        if(x < 0 || x >= n) return true;
        if(y < 0 || y >= m) return true;
        return false;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        memset(nums, 0, sizeof(nums));
        nums[0][0] = grid[0][0];
        int n = grid.size(); int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) continue;
                if(isBorder(i-1, j, n, m)){
                    nums[i][j] = nums[i][j-1] + grid[i][j];
                }
                else if(isBorder(i, j-1, n, m)){
                    nums[i][j] = nums[i-1][j] + grid[i][j];
                }
                else{
                    nums[i][j] = min(nums[i-1][j], nums[i][j-1]) + grid[i][j];
                }
            }
        }
        return nums[n-1][m-1];
    }
};