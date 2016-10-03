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
    ListNode* insert(ListNode* head, ListNode* x){
        if(!head){
            x->next = NULL;
            return x;
        }
        ListNode* p = head;
        while(p->next) p = p->next;
        p->next = x;
        x->next = NULL;
        return head;
    }
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode *l = NULL,*r = NULL, *p = head;
        while(p){
            ListNode* q = p->next;
            if(p->val < x) l = insert(l, p);
            else r = insert(r, p);
            p = q;
        }
        p = l;
        if(!p) return r;
        while(p->next){
            p = p->next;
        }
        p->next = r;
        return l;
    }
};