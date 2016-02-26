class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int times = 1;
        bool first = true;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0 && first)
                first = false;
            else
                times *= nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) ans.push_back(times);
            else if(!first) ans.push_back(0);
            else ans.push_back(times/nums[i]);
        }
        return ans;
    }
};