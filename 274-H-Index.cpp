#include <algorithm>
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        for(int i = n-1; i >= 0; i--){
            if(citations[i] < n-i){
                return n-i-1;
            }
        }
        if(n && citations[0] >= n) return n;
        return 0;
    }
};