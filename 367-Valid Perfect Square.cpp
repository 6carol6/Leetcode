class Solution {
private:
    bool binarySearch(int left, long long right, int num){
        if(left > right) return false;
        long long mid = (left + right)/2;
        if(mid*mid == num) return true;
        else if(mid*mid < num) return binarySearch(mid+1, right, num);
        else return binarySearch(left, mid-1, num);
    }
public:
    bool isPerfectSquare(int num) {
        return binarySearch(1, num, num);
    }
};