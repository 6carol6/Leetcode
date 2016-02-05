#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    string button[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(int depth, string digits, string str, vector<string>& ans){
        if(depth == digits.length()){
            ans.push_back(str);
            return;
        }
        if(depth == 0) str = "";
        int len = button[digits[depth]-'0'].length();
        for(int i = 0; i < len; i++){
            dfs(depth+1, digits, str+button[digits[depth]-'0'][i], ans);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string str = "";
        if(digits.length() == 0) return ans;
        dfs(0, digits, str, ans);
        return ans;
    }
};

int main(){
    Solution* s = new Solution;
    vector<string> tmp = s->letterCombinations("234");
    for(int i = 0; i < tmp.size(); i++){
        cout << tmp[i]<<endl;
    }
    delete s;
    return 0;
}