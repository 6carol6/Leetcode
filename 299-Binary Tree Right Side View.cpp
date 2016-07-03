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
    vector<int> ans;
    void bfs(TreeNode* root){
        if(root==NULL) return;
        deque<TreeNode*> queue;
        queue.push_back(root);
        while(!queue.empty()){
            int cnt = queue.size();
            ans.push_back(queue[cnt-1]->val);
            for(int i = 0; i < cnt; i++){
                if(queue[0]->left){
                    queue.push_back(queue[0]->left);
                }
                if(queue[0]->right){
                    queue.push_back(queue[0]->right);
                }
                queue.pop_front();
            }
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        bfs(root);
        return ans;
    }
};