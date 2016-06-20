class Solution {
private:
    void swap(int x, int y, vector<int>& nums){
        int tmp = nums[x];
        nums[x] = nums[y];
        nums[y] = tmp;
    }
    void dfs(int depth, vector<int>& nums, vector<vector<int> >& ans){
        if(depth == nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int i = depth; i < nums.size(); i++){
            swap(depth, i, nums);
            dfs(depth+1, nums, ans);
            swap(depth, i, nums);
        }
    }
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > ans;
        dfs(0, nums, ans);
        return ans;
    }
};