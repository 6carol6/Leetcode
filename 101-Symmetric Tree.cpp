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
    bool isReverse(TreeNode* r1, TreeNode* r2){
        if(r1 == NULL && r2 == NULL) return true;
        else if(r1 == NULL || r2 == NULL) return false;
        if(r1->val != r2->val) return false;
        if(isReverse(r1->left, r2->right)) return isReverse(r1->right, r2->left);
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isReverse(root->left, root->right);
    }
};