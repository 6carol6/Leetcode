#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
    vector<TreeNode*> dfs(vector<TreeNode*>& path, TreeNode* root, TreeNode* p){
        vector<TreeNode*> tmp;
        if(root == NULL) return tmp;
        if(root == p) return path;
        path.push_back(root);
        
        tmp = dfs(path, root->left, p);
        if(tmp.size() != 0) return tmp;
        tmp = dfs(path, root->right, p);
        if(tmp.size() == 0) path.pop_back();
        return tmp;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        vector<TreeNode*> tmp1, tmp2;
        vector<TreeNode*> ppath = dfs(tmp1, root, p);
        ppath.push_back(p);
        
        vector<TreeNode*> qpath = dfs(tmp2, root, q);
        qpath.push_back(q);
        for(int i = ppath.size()-1; i >= 0; i--){
            for(int j = qpath.size()-1; j >= 0; j--){
                if(ppath[i] == qpath[j]) return ppath[i];
            }
        }
    }
};

int main(){
    Solution* s = new Solution();
    TreeNode* root = new TreeNode(1);
    TreeNode* p = new TreeNode(2); TreeNode* q = new TreeNode(3);
    root->left = p; root->right = q;
    cout << s->lowestCommonAncestor(root, p, q)->val<<endl;
    return 0;
}