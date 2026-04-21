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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        ListNode *head2 = &dummy;
        dummy.next = head;
        ListNode* groupPrev = head2;
        int ogk = k;
        while(true){
            //need to get kth node firts
            ListNode *kth= groupPrev;
            for(int i =0;i <k ;i ++){
                if(!kth){
                    break;
                }
                kth= kth->next;
               
            }
            if(!kth){
                break;
            }
            ListNode* groupNext = kth->next;
            ListNode* prev = kth->next;
            ListNode* curr = groupPrev->next;
            while(curr!= groupNext){
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }
        return head2->next;
    }
};
