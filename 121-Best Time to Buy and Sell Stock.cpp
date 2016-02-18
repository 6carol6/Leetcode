/*
* 遍历一遍，找到目前最小的和最大的
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int ans = 0;
        int minP = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] - minP > ans) ans = prices[i] - minP;
            if(prices[i] < minP) minP = prices[i];
        }
        return ans;
    }
};