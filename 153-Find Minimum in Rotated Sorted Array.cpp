class Solution {
private:
    int binarysearch(vector<int>& nums, int left, int right){
        if(left == right) return left;
        int mid = (left + right)/2;
        if(nums[left] > nums[mid+1]){
            if(nums[mid] > nums[mid+1])
                return binarysearch(nums, mid+1, right);
            else
                return binarysearch(nums, left, mid);
        }else{
            if(nums[left] < nums[right]){
                return left;
            }else{
                return binarysearch(nums, mid+1, right);
            }
        }

    }
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        return nums[binarysearch(nums, 0, nums.size()-1)];
    }
};