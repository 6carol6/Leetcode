class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = (0+nums[nums.size()-1])*(n+1)/2;
        for(int i = 0; i < nums.size(); i++){
            ans -= nums[i];
        }
        return ans;
    }
};