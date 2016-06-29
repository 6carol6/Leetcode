class Solution {
private:
    int min(int a, int b){
        return a<b?a:b;
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        if(n == 0) return ans;
        int m = matrix[0].size();
        
        int circle = min(n, m)+1;

        for(int i = 0; i < circle/2; i++){
            for(int j = i; j < m-i; j++){
                ans.push_back(matrix[i][j]);
            }
            for(int j = i+1; j < n-i; j++){
                ans.push_back(matrix[j][m-i-1]);
            }
            if(n-i-1 > i){
                for(int j = m-i-2; j >= i; j--){
                    ans.push_back(matrix[n-i-1][j]);
                }
            }
            if(m-i-1 > i){
                for(int j = n-i-2; j > i; j--){
                    ans.push_back(matrix[j][i]);
                }
            }
        }
        return ans;
    }
};