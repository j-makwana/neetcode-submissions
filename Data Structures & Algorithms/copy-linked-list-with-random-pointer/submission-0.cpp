/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodes;
        Node* temp = head;
        while(temp){
            nodes[temp]= new Node(temp->val);
            temp = temp->next;
        }
        //now nodes exist;
        Node* temp2 = head;
        while(temp2){
            Node* cur_node = nodes[temp2];
            cur_node->next = nodes[temp2->next];
            cur_node->random = nodes[temp2->random];
            temp2= temp2->next;
        }
        return nodes[head];
        
    }
};
