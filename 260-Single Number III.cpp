class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int xxor = 0;
        for(int i = 0; i < nums.size(); i++){
            xxor = xxor^nums[i];
        }
        int tmp = xxor & (~(xxor-1));
        ans.push_back(0); ans.push_back(0);
        for(int i = 0; i < nums.size(); i++){
            if(tmp & nums[i]){
                ans[0] ^= nums[i];
            }
            else{
                ans[1] ^= nums[i];
            }
        }
        return ans;
    }
};