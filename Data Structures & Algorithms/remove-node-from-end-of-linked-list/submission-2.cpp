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
        ListNode* first = head;
        while(n>0){
            first = first->next;
            n--;
        }
        ListNode* prev= nullptr;
        ListNode* nth = head;
        while(first){
            prev = nth;
            nth =nth->next;
            first = first->next;
        }
        if(!prev && nth){
            return nth->next;
        }
        if(!prev && !nth){
            return nullptr;
        }
       
        prev->next = nth->next;
        nth->next = nullptr;
        return head;
 
    }
};
