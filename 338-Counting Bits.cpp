class Solution {
public:
    vector<int> countBits(int num) {
        //if(num == 0 || num == 1) return num;
        vector<int> ans(1, 0);
        int cnt = 0;
        while(cnt < num){
            int size = ans.size();
            for(int i = 0; i < cnt && cnt<num; i++, cnt++){
                ans.push_back(ans[i]+1);
            }
        }
        return ans;
    }
};