#include <memory.h>

class Solution {
private:
    int max(int a, int b){
        return (a>b)?a:b;
    }
public:
    int maxProduct(vector<string>& words) {
        int mask[1000];
        memset(mask, 0, sizeof(mask));
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                mask[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = i+1; j < words.size(); j++){
                if((mask[i] & mask[j]) == 0){
                    ans = max(ans, words[i].length() * words[j].length());
                }
            }
        }
        return ans;
    }
};