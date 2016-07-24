#include <algorithm>

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(int depth, int left, int n, int k){
        if(depth == k && tmp.size() == k){
            ans.push_back(tmp);
            return;
        }
        for(int i = left; i <= n; i++){
            tmp.push_back(i);
            dfs(depth+1, i+1, n, k);
            tmp.erase(tmp.end()-1);
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(0, 1, n, k);
        return ans;
    }
};