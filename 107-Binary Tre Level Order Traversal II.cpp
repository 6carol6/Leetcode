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
#include <algorithm>
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        deque<TreeNode*> queue;
        if(root == NULL) return ans;
        queue.push_back(root);
        while(!queue.empty()){
            int cnt = queue.size();
            vector<int> tmp;
            for(int i = 0; i < cnt; i++){
                tmp.push_back(queue[0]->val);
                if(queue[0]->left) queue.push_back(queue[0]->left);
                if(queue[0]->right) queue.push_back(queue[0]->right);
                queue.pop_front();
            }
            ans.push_back(tmp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};