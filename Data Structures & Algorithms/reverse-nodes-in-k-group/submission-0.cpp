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
        vector<pair<ListNode*, bool>> myseperateLists;
        int count = 0;
        while(head){
            if(count ==0){
                myseperateLists.push_back({head, false});

            }
            if(count == k-1){
                ListNode* temp = head->next;
                head->next = nullptr;
                head = temp;
                auto& node = myseperateLists.back();
                node.second = true;
                count = 0;
                continue;
            }
          
                head = head->next;
                count++;
            

        }
        //////reversal!
        for(int i =0; i<myseperateLists.size();i++){
            ListNode* node = myseperateLists[i].first;
            ListNode* prev = nullptr;
            while(node && myseperateLists[i].second){
                ListNode* temp = node->next;
                node->next = prev;
                prev = node;
                node= temp;
            }
            if(prev){
            myseperateLists[i].first = prev;
            }
        }

        ////link again?
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        for(int i =0; i< myseperateLists.size();i++){
            ListNode* node = myseperateLists[i].first;
            tail->next = node;
            ListNode* prev = nullptr;
            while(node->next){
                node = node->next;
            }
            tail = node;

        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
