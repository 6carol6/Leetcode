#include <vector>
class Solution {
private:
    int min(int a, int b){
        return a<b?a:b;
    }
public:
    int nthUglyNumber(int n) {
		vector<int> ans;
        int idx2=0, idx3=0, idx5=0;
        ans.push_back(1);
        for(int i = 1; i < n; i++){
            ans.push_back(min(ans[idx2]*2, min(ans[idx3]*3, ans[idx5]*5)));

            if(ans[i] == ans[idx2]*2) idx2++;
			if(ans[i] == ans[idx3]*3) idx3++;
			if(ans[i] == ans[idx5]*5) idx5++;
        }
        return ans[n-1];
    }
};