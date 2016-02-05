class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-3; i++){
            if(i!=0 && nums[i] == nums[i-1]) continue;
            int fixed1 = nums[i];
            for(int j = i+1; j < nums.size()-2; j++){
                if(j!=i+1 && nums[j] == nums[j-1]) continue;
                int fixed2 = nums[j];
                int left = j+1, right = nums.size()-1;
                while(left < right){
                    int a = nums[left] + nums[right], b = target - fixed1 -fixed2;
                    if(a > b){
                        right--;
                    }
                    else if(a < b){
                        left++;
                    }
                    else{
                        vector<int> vec;
                        vec.push_back(fixed1);vec.push_back(fixed2);
                        vec.push_back(nums[left]);vec.push_back(nums[right]);
                        ans.push_back(vec);
                        while(left++ < right && nums[left-1] == nums[left]);
                        while(right-- > left && nums[right+1] == nums[right]);
                    }
                }
            }
        }
        return ans;
    }
};