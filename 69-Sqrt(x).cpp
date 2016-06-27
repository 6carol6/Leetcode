class Solution {
private:
    int binarySearch(int left, long long right, int x){
        if(left > right) return right;
        long long mid = (left + right)/2;
        if(mid * mid == x) return mid;
        else if(mid * mid > x) return binarySearch(left, mid-1, x);
        else return binarySearch(mid+1, right, x);
    }
public:
    int mySqrt(int x) {
        return binarySearch(1, x, x);
    }
};