class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i]) continue;
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j]){
                    nums[i] = nums[j];
                    nums[j] = 0;
                    break;
                }
            }
        }
    }
};