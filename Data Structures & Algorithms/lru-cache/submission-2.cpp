class Node{
public:
    int value;
    Node* next;
    Node* prev;
    int key;
    Node(int key, int value){
        this->value = value;
        this->key = key;
        next = nullptr;
        prev = nullptr;
    }
};
class LinkedListwCache{
    public:
    unordered_map<int, Node*> tracker;
    Node* head;
    Node* tail;
    int capacity;
    int size;
    LinkedListwCache(int capacity){
        this->capacity = capacity;
        this->size = 0;
        this->head = new Node(0,0);
        this->tail = new Node(0,0);
        this->head->next = tail;
        this->tail->prev = head;

    };

    void append(int key, int value){
            ////if its already there, then remove it
            Node* toAdd = new Node(key, value);
           
            if(tracker.contains(key)){
                Node* torem = tracker[key];
                Node* prev = torem->prev;
                Node* next = torem->next;
                prev->next= next;
                next->prev = prev;
                size--;
                tracker.erase(key);
            }
            if(size == capacity){
                Node *toRem = head->next;
                head->next = toRem->next;
                toRem->next->prev = head;
                
                tracker.erase(toRem->key);
                size--;
            }
         
            tracker[key] = toAdd;
            Node *prev = tail->prev;
            prev->next = toAdd;
            toAdd->prev = prev;
            toAdd->next = tail;
            tail->prev = toAdd;
            size++;
        
    }
    int get(int key){
        if(tracker.contains(key)){
            append(key, tracker[key]->value);
            return tracker[key]->value;
        }


        return -1;
    }

};

class LRUCache {
    private:
    LinkedListwCache mylist;
public:
    LRUCache(int capacity): mylist(capacity) {
    }
    
    int get(int key) {
        return mylist.get(key);
        
    }
    
    void put(int key, int value) {
        mylist.append(key,value);
    }
};
