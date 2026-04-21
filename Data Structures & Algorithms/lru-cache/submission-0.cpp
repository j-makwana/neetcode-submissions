
class Node{
        
    public:
        int val;
        Node* prev;
        Node* next;
        int key;
        Node(int key, int value){
            this->val = value;
            this->prev=nullptr;
            this->next=nullptr;
            this->key = key;

        }
    
};
class LinkedList{
    public:
    int capacity;
    Node *head;
    Node *tail;
    LinkedList(int capacity){
        this->capacity = capacity;
        
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    };
    Node* append(Node* node, unordered_map<int, Node*>& tracker){
        if(capacity==0){
            //remove node from the front
            Node* toRemove = head->next;
            head->next = toRemove->next;
            if(toRemove->next){
                toRemove->next->prev = head;
            }
            tracker.erase(toRemove->key);
            delete toRemove;
            capacity++;
        }

        Node* lastnode = tail->prev;
        lastnode->next = node;
        node->prev = lastnode;
        node->next = tail;
        tail->prev = node;
        capacity--;
        return node;
    };
    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        capacity++;
        delete node;
    };



};

class LRUCache {
public:
    LinkedList* lru_cache;
    unordered_map<int, Node*> tracker;
    LRUCache(int capacity) {
        lru_cache = new LinkedList(capacity);
        
    }
    
    int get(int key) {
        if(tracker.count(key)){
            Node* node = tracker[key];
            int val = node->val;
            lru_cache->remove(node);
            Node* ptr = lru_cache->append(new Node(key, val), tracker);
            tracker[key] = ptr;
               return val;

        }
       
        //if it exists then we gotta delete and append to end;
        
        return -1;

    }
    
    void put(int key, int value) {
        if(tracker.count(key)){
              Node* node = tracker[key];
               lru_cache->remove(node);
               tracker.erase(key);
        }
      
        Node* new_node = new Node(key, value);
        Node* ptr = lru_cache->append(new_node, tracker);
        tracker[key]= ptr;

        
    }
};
