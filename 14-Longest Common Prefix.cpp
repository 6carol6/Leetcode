class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0)return ans;
        if(strs.size() == 1) return strs[0];
        for(int i = 0; i < strs[0].length(); i++){
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(strs[j][i] == '\0' || strs[j][i] != c) return ans;
            }
            ans += c;
        }
        return ans;
    }
};