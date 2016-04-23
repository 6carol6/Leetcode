#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

class Solution {
private:
    void dfs(int depth, string str, vector<string>& ans, stack<char> stk){
        if(depth == 0){
            while(!stk.empty()){
                str += ')';
                stk.pop();
            }
            //cout << str << endl;
            ans.push_back(str);
            return;
        }
        if(!stk.empty()){
            stk.pop();
            dfs(depth, str+")", ans, stk);
            stk.push('(');
        }
        stk.push('(');
        dfs(depth-1, str+"(", ans, stk);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        stack<char> stk;
        dfs(n, "", ans, stk);
        return ans;    
    }
};

int main(){
    Solution* s = new Solution;
    vector<string> vec = s->generateParenthesis(4);
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
    return 0;
}