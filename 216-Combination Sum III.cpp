class Solution {
private:
    vector<int> solution;
    void dfs(vector<vector<int>>& ans, int index, int sum, int num, int k, int n){
        if(num > k || sum > n){
            return;
        }else if(num == k && sum == n){
            ans.push_back(solution);
        }else{
            for(int i = index, i < 10; i++){
                sum += i;
                solution.push_back(i);
                dfs(ans, i+1, sum, num+1, k, n);
                solution.erase(solution.size()-1);
                sum -= i;
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        dfs(ans, 1, 0, 0, k, n);
        return ans;
    }
};