class Solution {
private:
    int ans = 0;
    bool check(int n, int row, int col, vector<string> tmp){
        for(int i = 0; i < row; i++){
            if(tmp[i][col] == 'Q') return false;
        }
        int i = row-1; int j = col+1;
        while(i >= 0 && j < n){
            if(tmp[i][j] == 'Q') return false;
            i--; j++;
        }
        i = row-1; j = col-1;
        while(i >=0 && j >= 0){
            if(tmp[i][j] == 'Q') return false;
            i--; j--;
        }
        return true;
    }
    void dfs(int depth, int n, vector<string> tmp){
        if(depth == 0){
            ans++;
            return;
        }
        for(int i = 0; i < n; i++){
            tmp[n-depth][i] = 'Q';
            //check
            if(!check(n, n-depth, i, tmp)){
                tmp[n-depth][i] = '.';
                continue;
            }
            dfs(depth-1, n, tmp);
            tmp[n-depth][i] = '.';
        }
    }
public:
    int totalNQueens(int n) {
        vector<string> tmp;
        for(int i = 0; i < n; i++){
            string str = "";
            for(int j = 0; j < n; j++){
                str += ".";
            }
            tmp.push_back(str);
        }
        dfs(n, n, tmp);
        return ans;
    }
};