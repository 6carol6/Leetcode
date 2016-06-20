#include <map>
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        int cnt = 0;
        for(map<int, int>::iterator it = m.begin(); it != m.end(); it++){
            for(int i = 0; i < it->second; i++){
                nums[cnt++] = it->first;
            }
        }
    }
};