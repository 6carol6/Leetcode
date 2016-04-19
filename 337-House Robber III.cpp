/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int max(int a, int b){
        return a>b?a:b;
    }
    void dfs(TreeNode* root, int& child, int& childchild){
        if(root == NULL) return;
        int lt = 0, lf = 0, rt = 0, rf = 0;
        dfs(root->left, lt, lf);
        dfs(root->right, rt, rf);
        child = lf+rf+root->val;
        childchild = max(lt, lf)+max(rt, rf);
    }
public:
    int rob(TreeNode* root) {
        int child = 0, childchild = 0;
        dfs(root, child, childchild);
        return max(child, childchild);
    }
};