/*
* 改成从前往后扫一遍，再从后往前扫一遍，就是O(N)了
*/
class Solution{
public:
    int maxProfit(vector<int>& prices){
        if(prices.size() <= 1) return 0;
        int n = prices.size();
        int* tmp = new int[prices.size()](); tmp[0] = 0;
        int* rev_tmp = new int[prices.size()](); rev_tmp[prices.size()-1] = 0;
        int minP = prices[0], maxPrice = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] - minP > maxPrice) maxPrice = prices[i] - minP;
            if(prices[i] < minP) minP = prices[i];
            tmp[i] = maxPrice;
        }
        int maxP = prices[prices.size()-1]; maxPrice = 0;
        for(int i = prices.size()-2; i >= 0; i--){
            if(maxP - prices[i] > maxPrice) maxPrice = maxP - prices[i];
            if(prices[i] > maxP) maxP = prices[i];
            rev_tmp[i] = maxPrice;
        }
        int ans = 0;
        for(int i = 0; i < prices.size(); i++){
            if(tmp[i] + rev_tmp[i] > ans) ans = tmp[i] + rev_tmp[i];
        }
        return ans;
    } 
};


/*
* 分别计算左边和右边买卖一次的最大利润，然后相加。
* 然而这种算法TLE了。复杂度是O(N^2)
*/

class Solution {
private:
    int maxProfitPart(int left, int right, vector<int>& prices){
        int max = 0;
        int minP = prices[left];
        for(int i = left+1; i <= right; i++){
            if(prices[i] - minP > max) max = prices[i] - minP;
            if(prices[i] < minP) minP = prices[i];
        }
        return max;
    }
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 1; i < prices.size(); i++){
            int profit = maxProfitPart(0, i, prices) + maxProfitPart(i, prices.size()-1, prices);
            if(ans < profit) ans = profit;
        }
        return ans;
    }
};
