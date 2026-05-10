struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool ending = false;

};
class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        this->root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = this->root;
        for(char c: word){
            if(!curr->children.contains(c)){
                curr->children[c] = new TrieNode();
            }
            curr= curr->children[c];

        }
        curr->ending = true;
        
    }
    
    bool search(string word) {
        TrieNode* curr = this->root;

        for(char c: word){
            if(!curr->children.contains(c)){
                return false;
            }
            curr = curr->children[c];
        }
        return curr->ending;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = this->root;

        for(char c: prefix){
            if(!curr->children.contains(c)){
                return false;
            }
            curr = curr->children[c];
        }
        return true;
        
    }
};
