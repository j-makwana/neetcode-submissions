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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        for(int i = 0; i<=n;i++){
            fast = fast->next;
        }
        ListNode* prev= &dummy;
        ListNode* nth = head;
        while(fast){
            prev = nth;
            nth =nth->next;
            fast = fast->next;
        }
 
        if(!prev && !nth){
            return nullptr;
        }
       
        prev->next = nth->next;
        nth->next = nullptr;
        return dummy.next;
 
    }
};
