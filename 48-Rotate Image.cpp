class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n; j++){
                int tmp = matrix[n-i-1][j];
                matrix[n-i-1][j] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};