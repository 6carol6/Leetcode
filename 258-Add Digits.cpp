//https://en.wikipedia.org/wiki/Digital_root
class Solution {
public:
    int addDigits(int num) {
        return (num-1)%9+1;
    }
};