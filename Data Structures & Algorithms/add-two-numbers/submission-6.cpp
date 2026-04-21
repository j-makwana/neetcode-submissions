/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *temp = &dummy;
        int carry = 0;
        while(l1 && l2){
            int val = l1->val + l2->val + carry;
            if(val >9){
                carry = 1;
            }else{
                carry = 0;
            }
            temp->next = new ListNode(val%10);
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int val = l1-> val + carry;
            if(val>9){
                carry = 1;
            }else{
                carry = 0;
            }
            temp->next = new ListNode(val%10);
            l1 = l1->next;
            temp = temp->next;
        }

        while(l2){
            int val = l2-> val + carry;
            if(val>9){
                carry = 1;
            }else{
                carry = 0;
            }
            temp->next = new ListNode(val%10);
            l2 = l2->next;
            temp = temp->next;

        }
        if(carry){
            temp->next = new ListNode(carry);
        }
            return dummy.next;

    }
};
