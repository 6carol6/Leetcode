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
    vector<TreeNode*> solver(int left, int right){
        vector<TreeNode*> tmp;
        if(left > right){
            tmp.push_back(NULL);
            return tmp;
        }else if(left == right){
            TreeNode* p = new TreeNode(left);
            tmp.push_back(p);
            return tmp;
        }
        for(int i = left; i <= right; i++){
            vector<TreeNode*> leftTree = solver(left, i-1);
            vector<TreeNode*> rightTree = solver(i+1, right);
            
            for(int j = 0; j < leftTree.size(); j++){
                for(int k = 0; k < rightTree.size(); k++){
                    TreeNode* p = new TreeNode(i);
                    p->left = leftTree[j];
                    p->right = rightTree[k];
                    tmp.push_back(p);
                }
            }
        }
        return tmp;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> t;
        if(n == 0) return t;
        return solver(1, n);
    }
};