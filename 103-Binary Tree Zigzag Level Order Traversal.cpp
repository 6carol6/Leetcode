/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <deque>

class Solution {
private:
    vector<vector<int>> ans;
    void bfs(TreeNode* root){
        if(root == NULL) return;
        deque<TreeNode*> queue;
        queue.push_back(root);
        bool is_leftToRight = true;
        while(!queue.empty()){
            int cnt = queue.size();
            vector<int> tmp(cnt, 0);
            for(int i = 0; i < cnt; i++){
                if(is_leftToRight){
                    tmp[i] = queue[0]->val;
                }
                else{
                    tmp[cnt-i-1] = queue[0]->val;
                }
                if(queue[0]->left) queue.push_back(queue[0]->left);
                if(queue[0]->right) queue.push_back(queue[0]->right);
                queue.pop_front();
            }
            is_leftToRight = !is_leftToRight;
            ans.push_back(tmp);
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bfs(root);
        return ans;
    }
};