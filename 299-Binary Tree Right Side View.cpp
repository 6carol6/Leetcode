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
            deque<TreeNode*> tmp;
            for(int i = 0; i < cnt; i++){
                if(queue[i]->left){
                    tmp.push_back(queue[i]->left);
                }
                if(queue[i]->right){
                    tmp.push_back(queue[i]->right);
                }
            }
            queue = deque(tmp);
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        bfs(root);
        return ans;
    }
};