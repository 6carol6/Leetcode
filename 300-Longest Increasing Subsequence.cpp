//O(n^2)
#include <memory.h>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int dp[10001];
        memset(dp, 0, sizeof(dp));
        int ans = 1; dp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] > nums[i]){
                    dp[j] = max(dp[i] + 1, dp[j]);
                    if(dp[j] > ans) ans = dp[j];
                }else{
                    dp[j] = max(dp[j], 1);
                }
            }
        }
        return ans;
    }
};

//O(nlogn)
#include<memory.h>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums){
        if(nums.size() == 0) return 0;
        int tmp[10001];
        memset(tmp, 0, sizeof(tmp));
        tmp[1] = nums[0];
        int ans=1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > tmp[ans]){
                tmp[++ans] = nums[i];
            }else if(nums[i] < tmp[ans]){
                int left = 1, right = ans;
                while(left < right){
                    int mid = (left+right)/2;
                    if(tmp[mid] > nums[i]){
                        right = mid-1;
                    }
                    else{
                        left = mid+1;
                    }
                 }
                 tmp[left] = nums[i];
            }
        }
        return ans;
    }
};