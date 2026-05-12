struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool ending;

};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
        
    }
    
    void addWord(string word) {
        //////pretty similar to issert
        TrieNode* curr = this->root;
        for(char c: word){
            if(!curr->children.contains(c)){
                curr->children[c]= new TrieNode();
            }
            curr= curr->children[c];
        }
        curr->ending = true;
        
    }
    bool helper(string &word, int index, TrieNode*node){
        for(int i = index; i< word.size();i++){
            if(word[i]=='.'){
                for(auto& [ch, node]: node->children){
                    if(helper(word, i+1, node)) return true;
                }
                return false;
            }
            if(!node->children.contains(word[i])){
                return false;
            }
            node= node->children[word[i]];
        }
        return node->ending;
    }

    bool search(string word) {
        ///here c can be a . as will
        ///when it is a . i every character in the dictionary becomes valid. 
        //this means in the level you find a .
        ///you loop throiug every value in the hashmap 
        TrieNode* curr = this->root;
        for(int i =0; i<word.size();i++){
            if(word[i]=='.'){
                for(auto& [ch, node]: curr->children){
                    if(helper(word, i+1, node)) return true;
                }
            }
            if(!curr->children.contains(word[i])) return false;

            curr = curr->children[word[i]];

        }
        return curr->ending;


        
    }
};
