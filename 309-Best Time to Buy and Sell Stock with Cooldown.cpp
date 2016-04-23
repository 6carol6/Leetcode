class Solution {
private:
    int max(int a, int b){
        return a>b?a:b;
    }
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int sellDP[10000], buyDP[10000];
        memset(sellDP, 0, sizeof(sellDP));
        memset(buyDP, 0, sizeof(buyDP));
        buyDP[0] = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            sellDP[i] = max(sellDP[i-1], buyDP[i-1]+prices[i]);
            if(i >= 2)
                buyDP[i] = max(buyDP[i-1], sellDP[i-2]-prices[i]);
            else
                buyDP[i] = max(buyDP[i-1], -prices[i]);
        }
        return sellDP[prices.size()-1];
    }
};