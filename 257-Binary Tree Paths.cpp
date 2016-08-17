
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <stdio.h>
#include <stdlib.h>
#include <string>
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(TreeNode* root){
        if(root == NULL) return;
        tmp.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            ans.push_back(tmp);
        }
        if(root->left != NULL)
            dfs(root->left);
        if(root->right != NULL)
            dfs(root->right);
        tmp.erase(tmp.end()-1);
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        vector<string> sans;
        char buffer[10];
        for(int i = 0; i < ans.size(); i++){
            string s="";
            for(int j = 0; j < ans[i].size()-1; j++){
                sprintf(buffer, "%d", ans[i][j]);
                //itoa(ans[i][j],buffer,10);
                s += buffer;
                s += "->";
            }
            sprintf(buffer, "%d", ans[i][ans[i].size()-1]);
            s+= buffer;
            sans.push_back(s);
        }
        return sans;
    }
};