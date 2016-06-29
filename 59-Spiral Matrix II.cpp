class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        //init
        for(int i = 0; i < n; i++){
            vector<int> tmp;
            for(int j = 0; j < n; j++){
                tmp.push_back(0);
            }
            ans.push_back(tmp);
        } 
        int cnt = 1;
        for(int i = 0; i < n/2; i++){
            for(int j = i; j < n-i; j++){
                ans[i][j] = cnt++;
            }
            for(int j = i+1; j < n-i; j++){
                ans[j][n-i-1] = cnt++;
            }
            for(int j = n-i-2; j >= i; j--){
                ans[n-i-1][j] = cnt++;
            }
            for(int j = n-i-2; j > i; j--){
                ans[j][i] = cnt++;
            }
        }
        if(n%2) ans[n/2][n/2] = cnt++;
        return ans;
    }
};