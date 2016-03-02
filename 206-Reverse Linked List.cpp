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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *pre, *cur, *pos;
        pre = head; cur = head->next; pos = cur->next;
        head->next = NULL;
        while(cur != NULL){
            cur->next = pre;
            pre = cur; cur = pos;
            if(pos != NULL) pos = pos->next;
        }
        return pre;
    }
};