#include <math.h>

class Solution {
private:
    int binarySearch(int n){
        int left = 0, right = 32;
        int mid;
        while(left < right){
           // cout << "("<<left<<", "<<right<<")"<<endl;
            mid = (left+right)/2;
            if((1<<mid) == n)
                return mid;
            else if((1<<mid) > n)
                right = mid;
            else
                left = mid+1;
        }
        return right;
    }
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n) return m;
        int sub = n - m;
        int offset = binarySearch(sub);
      //  cout << offset<<endl;
        int ans = 0;
        //offset++;
        //if(offset == 32) return 0;
        while(pow(2,offset) < n){
            ans += (m&(1 << offset)) & (n&(1 << offset));
            offset++;
        }
        return ans;
    }
};

//solution2
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int bit = 0;  
        while(m!=n) {  
            m>>=1;  
            n>>=1;  
            bit++;  
        }  
        return m<<bit; 
    }
};