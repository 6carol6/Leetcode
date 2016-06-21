#include <algorithm>
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int cnt = 1;
        for(int i = digits.size()-1; i >= 0; i--){
            int tmp = digits[i]+cnt;
            if(tmp == 10){
                cnt = 1;
                ans.push_back(0);
            }else{
                cnt = 0;
                ans.push_back(tmp);
            }
        }
        if(cnt == 1) ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};