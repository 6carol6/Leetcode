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
    TreeNode* work(vector<int>& preorder, int begin1, int end1, vector<int>& inorder, int begin2, int end2){
        if(begin1 >= end1) return NULL;
        TreeNode* root = new TreeNode(preorder[begin1]);
        int idx = 0;
        for(idx = begin2; idx < end2; idx++){
            if(inorder[idx] == preorder[begin1])break;
        }
        if(idx == end2) return NULL;
        int offset = idx-begin2;
        root->left = work(preorder, begin1+1, begin1+offset+1, inorder, begin2, idx);
        root->right = work(preorder, begin1+offset+1, end1, inorder, idx+1, end2);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return work(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};