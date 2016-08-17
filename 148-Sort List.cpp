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
    ListNode* findMid(ListNode* head){
        ListNode* p = head;
        ListNode* q = head;
        ListNode* p_prev = p;
        while(q != NULL && q->next != NULL){
            p_prev = p;
            p = p->next;
            q = q->next->next;
        }
        p_prev->next = NULL; //cut
        return p;
    }
    void insert(ListNode** head, ListNode** tail,ListNode* p){
        if(*head == NULL) {*head = p;*tail = p;}
        else{
            (*tail)->next = p;
            *tail = p;
        }
    }
    ListNode* merge(ListNode* p, ListNode* q){
       ListNode* head = NULL;
       ListNode* tail = NULL;
       while(p != NULL && q != NULL){
           ListNode* n1 = p; ListNode* n2 = q;
           //cout << p->val << ","<<q->val<<endl;
           if(n1->val <= n2->val){
               p = p->next;
               n1->next = NULL;
               insert(&head,&tail, n1);
           }else{
               q = q->next;
               n2->next = NULL;
               insert(&head,&tail, n2);
           }
       }
       if(p != NULL) insert(&head, &tail, p);
       if(q != NULL) insert(&head, &tail, q);
       
       return head;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* mid = findMid(head);
        //cout << mid->val<<endl;
        ListNode* p = sortList(head);
        ListNode* q = sortList(mid);
        return merge(p, q);
    }
};