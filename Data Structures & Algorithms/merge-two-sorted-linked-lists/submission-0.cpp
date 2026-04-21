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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
   
        ListNode dummyHead(0);
        ListNode* tail = &dummyHead;
        while(list1 && list2){
            if(list1->val < list2->val){
                ListNode *temp = list1->next;
                tail->next = list1;
                
                list1 = temp;
            }else{
                ListNode *temp = list2->next;
                tail->next = list2;
                list2 = temp;

            }
            tail = tail->next;

        }
        tail->next= (list1==nullptr)?  list2: list1;
    
        return dummyHead.next;

        
    }
};
