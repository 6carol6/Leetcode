/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode p = head;
        int carry = 0;
        int sum = 0;
        for(; l1!=null && l2!=null; l1=l1.next, l2=l2.next){
            sum = l1.val + l2.val + carry;
            carry = sum/10;
            ListNode q = new ListNode(sum%10);
            p.next = q;
            p = p.next;
        }
        while(l1!=null){
            sum = l1.val + carry;
            carry = sum/10;
            ListNode q = new ListNode(sum%10);
            p.next = q;
            p = p.next;
            l1 = l1.next;
        }
        while(l2!=null){
            sum = l2.val + carry;
            carry = sum/10;
            ListNode q = new ListNode(sum%10);
            p.next = q;
            p = p.next;
            l2 = l2.next;
        }
        if(carry != 0){
            ListNode q = new ListNode(1);
            p.next = q;
            p = p.next;
        }
        return head.next;
    }
}