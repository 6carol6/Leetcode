#include <map>
#include <vector>
#include <memory.h>
#include <iostream>
#include <algorithm>
using namespace std;

int cmp(const void* a, const void* b){
    return *(const int*)b > *(const int*)a;
}

class Solution {
private:
    int freq[10001][2];

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        memset(freq, 0, sizeof(freq));
        map<int, int> m;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) != m.end())
                m[nums[i]]++;
            else
                m[nums[i]] = 1;
        }
        int cnt = 0;
        for(map<int, int>::iterator it = m.begin(); it != m.end(); it++){
            freq[cnt][1] = it->first;
            freq[cnt][0] = it->second;
            cnt++;
        }
        qsort(freq, cnt, sizeof(int)*2, cmp);
        for(int i = 0; i < k; i++){
            ans.push_back(freq[i][1]);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(2);nums.push_back(3);nums.push_back(2);nums.push_back(2);
    vector<int> ans = s.topKFrequent(nums, 1);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}