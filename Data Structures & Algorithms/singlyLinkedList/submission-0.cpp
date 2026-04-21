#include <iostream> 
using namespace std;
class Node{
public:
    int data;
    Node *next;

    Node(){
        data = 0;
        next = nullptr;
    }
    Node(int data){
        this->data = data;
        this->next= nullptr;
    }
};
class LinkedList {
private:
    Node *head;
    Node *tail;
    int _size;
    
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
       _size= 0;
    }


    int get(int index) {
        if(index<0 || index>= _size){
            return -1;
        }
        Node *curNode = head;
        int size2= 0;
        while (size2< index){
            curNode= curNode->next;
            size2++;
        
        }
        return curNode->data;


    }

    void insertHead(int val) {
        Node *newNode = new Node(val);
        if (head == nullptr){
            head = newNode;
            tail = newNode;
            _size++;
            return;
        }
        newNode->next = this->head;
        this->head= newNode;
         _size++;
    }
    
    void insertTail(int val) {
        Node *newNode = new Node(val);
        if (tail== nullptr && head == nullptr){
            head = newNode;
            tail = newNode;
            _size++;
            return;

        }
        tail->next = newNode;
        this->tail= newNode;
         _size++;
      
    }

    bool remove(int index) {
        Node *curNode = head;
        if(index <0 || index >= _size){
            return false;
        }

        int size = 0;
        //conditions when remove is at 0 , when remove is in the middle,when remove is at the end
        ///remove at 0, need to set the head to simply point at 
        if(index ==0){
            this->head = curNode->next;
            delete curNode;
            _size--;
            if(_size ==0){
                tail = nullptr;
            }
            return true;
        }
      
        while(size <index -1){
            curNode= curNode->next;
            size++;
        }
        Node* nodeToDelete = curNode->next;
        curNode->next= nodeToDelete->next;
        delete nodeToDelete;
        _size--;
        //if last node remoced update tail;
        if(index == _size){
            this-> tail = curNode;
        }
        return true;


    }

    vector<int> getValues() {
        vector<int> values;
        Node *curNode = head;
        while(curNode != nullptr){
            values.push_back(curNode->data);
            curNode= curNode->next;
        }
        return values;
        
    }
};
