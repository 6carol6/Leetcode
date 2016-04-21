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
    bool hasCycle(ListNode *head) {
        ListNode* p = head, *q = head;
        if(p == NULL || p->next == NULL) return false;
        while(p != NULL && q!= NULL){
            p = p->next;
            if(q->next == NULL) break;
            q = q->next->next;
            if(p == q) break;
        }
        if(p != NULL && p == q) return true;
        return false;
    }
};