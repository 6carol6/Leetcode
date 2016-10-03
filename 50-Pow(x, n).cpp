class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1, tmp = x;
        long long nn = n;
        bool tag = false;
        if(nn < 0){
            nn = -nn;
            tag = true;
        } 
        while(nn){
            if(nn%2) ans *= tmp;
            tmp *= tmp;
            nn = nn >> 1;
        }
        if(tag) ans = 1/ans;
        return ans;
    }
};