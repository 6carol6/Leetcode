//如果是4的倍数，不管如何取，对方总能让结果剩4的倍数。如果是剩了4个是无论如何都不能赢的。
class Solution {
public:
    bool canWinNim(int n) {
        return n%4;
    }
};