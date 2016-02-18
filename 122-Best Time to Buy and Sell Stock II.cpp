/*
* 遍历一遍，只要有的赚就买卖
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int p = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[p]){
                ans += prices[i] - prices[p];
            }
            p = i;
        }
        return ans;
    }
};