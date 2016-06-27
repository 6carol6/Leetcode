class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;
        int ans = countNumbersWithUniqueDigits(n-1);
        int cnt = 9;
        int mul = 1;
        bool first = true;
        while(n > 0 && cnt > 1){
            n--;
            mul *= cnt;
            if(first) first = false;
            else cnt--;
        }
        return ans+mul;
    }
};