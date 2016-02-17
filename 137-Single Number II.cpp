/*
* 一个有意思的跟数字逻辑电路(卡诺图)有关的题
* https://leetcode.com/discuss/81165/explanation-manipulation-method-might-easier-understand
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ONE = 0, TWO = 0;
        for(int i = 0; i < nums.size(); i++){
            ONE = (~TWO) & (ONE^nums[i]);
            TWO = (~ONE) & (TWO^nums[i]);
        }
        return ONE;
    }
};