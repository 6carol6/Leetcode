class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> stk;
        vector<int> pre;
        int tmp = 0;
        for(int i = 0; i < preorder.size(); i++){
            if(preorder[i] == ','){
                pre.push_back(tmp);
                tmp = 0;
            }
            else if(preorder[i] == '#'){
                pre.push_back(-1);
            }
            else{
                tmp = tmp*10+(preorder[i]-'0');
            }
        }
        pre.push_back(tmp);

        for(int i = 0; i < pre.size(); i++){
            if(pre[i] == -1){
                if(stk.empty()) return false;
                while(!stk.empty() && stk.top() == -1){
                    stk.pop();
                    if(stk.empty()) return false;
                    stk.pop();
                }
                stk.push(-1);
            }else{
                stk.push(pre[i]);
            }
        }
        if(stk.size() == 1 && stk.top() == -1) return true;
        return false;
    }
};