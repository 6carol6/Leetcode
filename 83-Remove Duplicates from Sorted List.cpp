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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* p = head;
        ListNode* q = p->next;
        while(q){
            if(q->val == p->val){
                p->next = q->next;
                delete q;
                q = p->next;
            }else{
                p = p->next;
                q = p->next;
            }
        }
        return head;
    }
};