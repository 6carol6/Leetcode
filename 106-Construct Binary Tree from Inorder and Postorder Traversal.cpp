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
    TreeNode* work(vector<int>& inorder, int begin1, int end1, vector<int>& postorder, int begin2, int end2){
        if(begin2 > end2) return NULL;
        TreeNode* root = new TreeNode(postorder[end2]);
        int idx = begin1;
        for(; idx <= end1; idx++){
            if(inorder[idx] == postorder[end2]) break;
        }
        if(idx == end1+1) return NULL;
        int offset = end1-idx;
        root->left = work(inorder,begin1,idx-1,postorder,begin2,end2-offset-1);
        root->right = work(inorder,idx+1,end1,postorder,end2-offset-1,end2-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return work(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};