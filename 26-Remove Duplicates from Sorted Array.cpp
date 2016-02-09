class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;
        if(nums.size() == 0) return ans;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]) ans++;
            else{
                vector<int>::iterator it = nums.begin()+i;
                nums.erase(it);
                i--;
            }
        }
        return ++ans;
    }
};