class Solution {
private:
    int abs(int x){
        return (x<0)?-x:x;
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0, min = 999999;
        if(nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++){
            if(i!=0 && nums[i] == nums[i-1]) continue;
            int fixed = nums[i];
            int left = i+1, right = nums.size()-1;
            while(left < right){
                int num = fixed+nums[left]+nums[right];
                int distance = abs(num-target);
                if(min > distance){
                    min = distance;
                    ans = num;
                }
                if(num-target > 0) right--;
                else if(num-target < 0) left++;
                else{
                    return ans;
                }
            }
        }
        return ans;
    }
};