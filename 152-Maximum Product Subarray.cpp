class Solution {
private:
    inline int max(int a, int b){
        return a>b?a:b;
    }
    inline int min(int a, int b){
        return a<b?a:b;
    }
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() <= 0) return 0;
        int ans = nums[0];
        int max_local = nums[0];
        int min_local = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int max_copy = max_local;
            max_local = max(max(max_local*nums[i], nums[i]), min_local*nums[i]);
            min_local = min(min(min_local*nums[i], nums[i]), max_copy*nums[i]);
            if(ans < max_local) ans = max_local;
        }
        return ans;
    }
};