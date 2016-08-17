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
    bool dfs(TreeNode* root, int sum, int s){
        if(root == NULL) return false;
        s += root->val;
        if(s > sum) return false;
        if(root->left == NULL && root->right == NULL){ //leaf
            if(s == sum){
                return true;
            }
        }
        if(root->left != NULL){
            if(dfs(root->left, sum, s)) return true;
        }
        if(root->right != NULL){
            return dfs(root->right, sum, s);
        }
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum, 0);
    }
};