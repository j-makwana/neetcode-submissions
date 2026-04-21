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
    void reorderList(ListNode* head) {
        if(!head) return;
        if(!head && !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ////
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(second){
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        //both lists seperated;
        ListNode* r= prev;
        ListNode* l= head;
        while(l&&r){
            ListNode* temp1= l->next;
            ListNode* temp2 = r->next;
            l->next = r;
            r->next = temp1;
            l = temp1;
            r= temp2;
        }
      
    }
};
