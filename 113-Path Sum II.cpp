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
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(TreeNode* root, int sum, int s){
        if(root == NULL) return;
        s += root->val;
        tmp.push_back(root->val);
        if(root->left == NULL && root->right == NULL){ //leaf
            if(s == sum){
                ans.push_back(tmp);
            }
        }
        if(root->left != NULL)
            dfs(root->left, sum, s);
        if(root->right != NULL)
            dfs(root->right, sum ,s);
        tmp.erase(tmp.end()-1);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum, 0);
        return ans;
    }
};