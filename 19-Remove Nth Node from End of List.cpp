//双指针，头一个指针先走n步，然后两个指针一起走，头一个指针指向尾巴的时候，删除后一个指向的那个元素
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
		for(int i = 0; i < n; i++){
			p = p->next;
		}
		ListNode* q = head;
		if(p == NULL){
			head = head->next;
			q->next = NULL;
			delete q;
			return head;
		}
		while(p->next != NULL){
			p = p->next;
			q = q->next;
		}
		p = q->next;
		q->next = p->next;
		p->next = NULL;
		delete p;
		return head;
    }
};