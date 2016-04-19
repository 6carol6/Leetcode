#include <iostream>
#include <vector>
using namespace std;



// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
private:
    TreeNode* quickInsert(int left, int right, vector<int>& nums){
        if(left >= right) return NULL;
        int mid = (left+right)/2;
        TreeNode* treeNode = new TreeNode(nums[mid]);
       // cout << treeNode->val<<endl;
        treeNode->left = quickInsert(left, mid, nums); treeNode->right = quickInsert(mid+1, right, nums);
        return treeNode;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return quickInsert(0, nums.size(), nums);
    }
};

int main(){
    vector<int> nums;
    for(int i = 0; i < 10; i++){
        nums.push_back(i);
    }
    Solution s;
    TreeNode* root = s.sortedArrayToBST(nums);
    //cout << root->val<<endl;
    return 0;
}