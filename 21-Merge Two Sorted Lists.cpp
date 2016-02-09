/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = l1; ListNode* q = l2;
        ListNode* ans = NULL;
        ListNode* ans_p, * ans_q;
        
        while(p != NULL && q != NULL){
            if(p->val <= q->val){
                ans_q = p;
                p = p->next;
            }else{
                ans_q = q;
                q = q->next;
            }
            if(ans == NULL){
                ans = ans_q;
                ans_p = ans;
            }else{
                ans_p->next = ans_q;
                ans_p = ans_q;
            }
        }
        if(p){
            if(!ans) ans = p;
            else ans_p->next = p;
        }
        if(q){
            if(!ans) ans = q;
            else ans_p->next = q;
        } 
        return ans;
    }
};