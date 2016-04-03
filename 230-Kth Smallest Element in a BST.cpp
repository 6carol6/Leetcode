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
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        return 1+dfs(root->left)+dfs(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL){
            return 0;
        }
        int left = dfs(root->left);
        if(left+1 == k){
            return root->val;
        }
        else if(left+1 > k){
            return kthSmallest(root->left, k);
        }else{
            return kthSmallest(root->right, k-left-1);
        }
    }
};