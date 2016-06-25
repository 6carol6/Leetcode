class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0){
            vector<int> ans;
            ans.push_back(0);
            return ans;
        }
        vector<int> copy = grayCode(n-1);
        vector<int> ans(copy);
        for(int i = copy.size()-1; i >= 0; i--){
            ans.push_back((1<<(n-1)) | copy[i]);
        }
        return ans;
    }
};