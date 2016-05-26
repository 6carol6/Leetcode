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
    bool valid(TreeNode* root, long long min, long long max){
        if(root == NULL) return true;
        if(root->val <= min || root->val >= max) return false;
        if(valid(root->left, min, root->val) == true) return valid(root->right, root->val, max);
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, -21474836479, 2147483648);
    }
};