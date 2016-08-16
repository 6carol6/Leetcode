#include <memory.h>
class Solution {
private:
    int min(int a, int b){
        return a<b?a:b;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int dp[1001][1001];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i = 0; i < matrix[0].size(); i++){
            if(matrix[0][i] == '1'){
                ans = 1;
                dp[0][i] = 1;
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][0] == '1'){
                ans = 1;
                dp[i][0] = 1;
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
                    if(dp[i][j] > ans) ans = dp[i][j];
                }
            }
        }
        return ans*ans;
    }
};