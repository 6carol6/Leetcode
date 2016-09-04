/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* reverse(ListNode* head){
        ListNode *fast = head, *slow = head, *cut=NULL;
        while(fast && fast->next){
            fast = fast->next->next;
            cut = slow;
            slow = slow->next;
        }
        //if(!slow)
        cut->next = NULL;
        //cout << slow->val<<endl;
        ListNode* p = slow->next;
        ListNode* nxt = p->next;
        slow->next = NULL;
        while(p){
            p->next = slow;
            slow = p;
            p = nxt;
            if(nxt)
                nxt = nxt->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode *p = h1, *q = h2;
        while(p&&q){
            ListNode* t = p->next,*t2=q->next;
            //cout << p->val << q->val<<endl;
            p->next = q;
            if(t)
                q->next = t;
            p = t; q = t2;
        }
        return h1;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode* head2 = reverse(head);
        head = merge(head, head2);
    }
};