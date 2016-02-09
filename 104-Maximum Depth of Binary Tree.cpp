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
        return (a>b)?a:b;
    }
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(dfs(root->left), dfs(root->right));
    } 
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(dfs(root->left),dfs(root->right))+1;
    }
};
