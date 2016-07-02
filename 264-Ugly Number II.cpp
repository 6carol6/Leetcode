#include <vector>
class Solution {
private:
    int min(int a, int b){
        return a<b?a:b;
    }
public:
    int nthUglyNumber(int n) {
        int ans;
        vector<int> v2, v3, v5;
        v2.push_back(1); v3.push_back(1); v5.push_back(1);
        while(n--){
            ans = min(v2[0], min(v3[0], v5[0]));
            if(v2[0] == ans) v2.remove(v2.begin());
            if(v3[0] == ans) v3.remove(v3.begin());
            if(v5[0] == ans) v5.remove(v5.begin());
            v2.push_back(ans*2);
            v3.push_back(ans*3);
            v5.push_back(ans*5);
        }
        return ans;
    }
};