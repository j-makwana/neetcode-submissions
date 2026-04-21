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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        if(lists.empty()){
            return {};
        }
        for(ListNode* n: lists){
            pq.push({n->val, n});
        }
        ListNode dummy(0);
        ListNode *temp = &dummy;
        while(!pq.empty()){
            auto n = pq.top();
            
            pq.pop();
            temp->next = n.second;
            temp = temp->next;
            if(n.second->next){
            pq.push({n.second->next->val, n.second->next});
            }
        }
        return dummy.next;

    }
};
