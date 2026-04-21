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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* slow = nullptr;
        while(temp!=nullptr){
            ListNode* temp2 = temp->next;
            temp->next = slow;
            slow = temp;
            temp = temp2;
            
        }
        return slow;
        
    }
};
