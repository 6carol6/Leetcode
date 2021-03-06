#include <algorithm>
class Solution {
private:
    vector<int>  solution;
    void dfs(vector<vector<int> >& ans, vector<int>& candidates, int target, int sum, int index){
        if(sum == target){
            ans.push_back(solution);
        }
        else if(sum > target){
            return;
        }else{
            for(int i = index; i < candidates.size(); i++){
                solution.push_back(candidates[i]);
                sum+=candidates[i];
                dfs(ans, candidates, target, sum, i);
                sum-=candidates[i];
                solution.erase(solution.end()-1);
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        dfs(ans, candidates, target, 0, 0);
        return ans;
    }
};