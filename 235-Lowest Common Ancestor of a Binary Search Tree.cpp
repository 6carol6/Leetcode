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
    int min(int a, int b){
        return a<b?a:b;
    }
    int max(int a, int b){
        return a>b?a:b;
    }
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return root;
        if(min(p->val, q->val) <= root->val && max(p->val, q->val) >= root->val){
            return root;
        }
        else if(p->val < root->val){
            return dfs(root->left, p, q);
        }
        else{
            return dfs(root->right, p, q);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};