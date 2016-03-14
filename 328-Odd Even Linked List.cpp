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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* oddh = head;
        ListNode* evenh = head->next;
        ListNode* oddp = head;
        ListNode* evenp = evenh;
        while(oddp->next != NULL && evenp != NULL){
            oddp->next = evenp->next;
            if(evenp->next != NULL){
                oddp = oddp->next;
                evenp->next = oddp->next;
                if(evenp->next != NULL){
                    evenp = evenp->next;
                }
            }
        }
        evenp->next = NULL;
        oddp->next = evenh;
        return oddh;
    }
};