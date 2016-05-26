/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

#include <deque>
#include <vector>

class Solution {
private:
    vector<TreeLinkNode*> bfs(TreeLinkNode *root){
        deque<TreeLinkNode*> queue;
        vector<TreeLinkNode*> vec;
        if(root == NULL) return vec;
        queue.push_back(root);
        vec.push_back(root);
        vec.push_back(NULL);
        while(!queue.empty()){
            int cnt = queue.size();
            for(int i = 0; i < cnt; i++){
                TreeLinkNode* p = queue[i];
                if(p->left != NULL){
                    queue.push_back(p->left);
                    vec.push_back(p->left);
                }
                if(p->right != NULL){
                    queue.push_back(p->right);
                    vec.push_back(p->right);
                }
            }
            vec.push_back(NULL);
            while(cnt--)
                queue.pop_front();
        }
        return vec;
    }
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        vector<TreeLinkNode*> ans = bfs(root);
        for(int i = 0; i < ans.size()-1; i++){
            if(ans[i] != NULL)
                ans[i]->next = ans[i+1];
        }
    }
};