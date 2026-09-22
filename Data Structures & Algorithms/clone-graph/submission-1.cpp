/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        Node* node_copy = new Node(node->val);
        unordered_map<Node*, Node*> visited;

        visited[node] = node_copy;
        dfs(node, visited);
        return visited[node];
    }
    void dfs(Node* node, unordered_map<Node*, Node*>& tracker) {
        for (Node*& n : node->neighbors) {
            if (!tracker.contains(n)) {
                // add n t visited
                Node* new_node = new Node(n->val);
                tracker[n] = new_node;
                tracker[node]->neighbors.push_back(tracker[n]);
                dfs(n, tracker);
            } else {
                
                    tracker[node]->neighbors.push_back(tracker[n]);
                
                
            }
        }
    }
};
