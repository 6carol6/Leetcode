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
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* right = root->right;
        TreeNode* left = root->left;
        if(left != NULL){ 
            flatten(left);
            root->right = left;
            root->left = NULL;
            while(left->right != NULL) left = left->right;
            left->right = right;
        }
        if(right != NULL) flatten(right);
    }
};