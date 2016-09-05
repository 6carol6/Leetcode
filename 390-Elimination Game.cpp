class Solution {
private:
    int l2r(int n){
        if(n == 1 || n == 2) return n;
        if(n&1) return 2*r2l((n-1)/2);
        else return 2*r2l(n/2);
    }
    int r2l(int n){
        if(n == 1 || n == 2) return 1;
        if(n&1) return 2*l2r((n-1)/2);
        else return 2*l2r(n/2)-1;
    }
public:
    int lastRemaining(int n) {
        return l2r(n);
    }
};