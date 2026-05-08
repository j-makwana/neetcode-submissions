/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {

    private:
        queue<string> mydata;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "n";
        }
        string base = "";
        base += to_string(root->val);
        string left = serialize(root->left);
        string right = serialize(root->right);
        base += "," + left;
        base += ","+right;
        return base;

    }

    void tokenize(const string& data, char delim =','){
        stringstream ss(data);
        string tok;
        while(getline(ss, tok, delim)){
            mydata.push(tok);
        }
    }
    TreeNode* deserializeHelper(){
        if(mydata.front()=="n"){
            mydata.pop();
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(mydata.front()));
        mydata.pop();
        TreeNode* left = deserializeHelper();
        
        TreeNode* right = deserializeHelper();
   
        root->left = left;
        root->right = right;
        return root;


    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        tokenize(data);
        return deserializeHelper();
        // if(data=='n'){
        //     return nullptr;
        // }

        // TreeNode* root = new TreeNode(data[0]);
        // TreeNode* left = deserialize(data[1])

        return nullptr;
    }
};
