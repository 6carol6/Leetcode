//排序之后，固定一个数，从两边往中间遍历求和
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++){
            if(i!=0 && nums[i] == nums[i-1]) continue;
            int fixed = nums[i];
            int left = i+1, right = nums.size()-1;
            while(left < right){
                if(nums[left]+nums[right] > -fixed){
                    right--;
                }
                else if(nums[left]+nums[right] < -fixed){
                    left++;
                }
                else{
                    vector<int> vec;
                    vec.push_back(fixed);vec.push_back(nums[left]);vec.push_back(nums[right]);
                    ans.push_back(vec);
                    while(left++ < right && nums[left-1] == nums[left]);
                    while(right-- > left && nums[right+1] == nums[right]);
                }
            }
        }
        return ans;
    }
};