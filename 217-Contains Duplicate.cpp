class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> snums;
        for(int i = 0; i < nums.size(); i++){
            snums.insert(nums[i]);
        }
        return snums.size() != nums.size();
    }
};