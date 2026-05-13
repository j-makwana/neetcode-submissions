

struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool ending;
};
class Trie{
        
    public:
        TrieNode* root;
        Trie(){
            this->root = new TrieNode();
        } ;   

        void insert(string word){
            TrieNode* curr = this->root;
            for(char c: word){
                if(!curr->children.contains(c)){
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }
            curr->ending = true;

        }

        bool startsWith(string word){
            TrieNode* curr = this->root;
            for(char c: word){
                if(!curr->children.contains(c)){
                    return false;
                }
                curr = curr->children[c];
            }
            return true;
        }
};


class Solution {
    private:
        set<pair<int, int>> visit;
        set<string> res;
        int rowMax;
        int colMax;
        vector<vector<char>> board;

public:
    bool boundschecker(int row, int col){
        if(row<0 || row>=rowMax || col<0|| col>=colMax){
            return false;
        }
        return true;
    }
    void dfs(int r, int c, TrieNode* node, string word){
        if(!boundschecker(r,c)){
            return;
        }
        if(visit.contains({r,c})){
            return;
        }
        if(!node->children.contains(board[r][c])){
            return;
        }

        visit.insert({r,c});
        node = node->children[board[r][c]];
        word+= board[r][c];
        if(node->ending){
            res.insert(word);
        }
        dfs(r+1,c, node,word);
        dfs(r-1,c, node,word);
        dfs(r,c+1, node,word);
        dfs(r,c-1, node,word);
        visit.erase({r,c});
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            Trie* myTrie = new Trie();
            this->board = board;
            rowMax = board.size();
            colMax = board[0].size();
            for(string word: words){
                myTrie->insert(word);
            }
            for(int r =0 ; r< rowMax; r++){
                for(int c = 0; c< colMax; c++){
                    dfs(r, c, myTrie->root, "");
                }
            }
            vector<string> vecres(res.begin(), res.end());
            return vecres;




    }
};
