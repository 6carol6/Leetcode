#include <memory.h>

class Solution {
private:
    vector<int> tmp;
    bool judge[10000];
    void dfs(int depth, vector<int>& nums, vector<vector<int> >& ans){
        if(depth == nums.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(judge[i]) continue;
            if(i && nums[i] == nums[i-1] && judge[i-1]) continue;
            judge[i] = true;
            tmp.push_back(nums[i]);
            dfs(depth+1, nums, ans);
            judge[i] = false;
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        memset(judge, 0, sizeof(judge));
        sort(nums.begin(), nums.end());
        dfs(0, nums, ans);
        return ans;
    }
};