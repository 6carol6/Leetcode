#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
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
    void dfs(int depth, int n, vector<vector<string> >& ans, vector<string> tmp){
        if(depth == 0){
            ans.push_back(tmp);
            return;
        }
        for(int i = 0; i < n; i++){
            tmp[n-depth][i] = 'Q';
            //check
            if(!check(n, n-depth, i, tmp)){
                tmp[n-depth][i] = '.';
                continue;
            }
            dfs(depth-1, n, ans, tmp);
            tmp[n-depth][i] = '.';
        }
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> tmp;
        for(int i = 0; i < n; i++){
            string str = "";
            for(int j = 0; j < n; j++){
                str += ".";
            }
            tmp.push_back(str);
        }
        dfs(n, n, ans, tmp);
        return ans;
    }
};

int main(){
    Solution* s = new Solution();
    vector<vector<string> > ans = s->solveNQueens(8);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}