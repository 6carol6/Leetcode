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
    bool dfs(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        else if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;
        return dfs(p->left, q->left) && dfs(p->right, q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }
};