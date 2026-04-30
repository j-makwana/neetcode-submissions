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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        deque<TreeNode*> myq;
        vector<int> result;
        myq.push_back(root);
        while(!myq.empty()){
            int q_size = myq.size();
            for(int i =0; i< q_size;i++){
                TreeNode* node = myq.front();
                if(node->left){
                    myq.push_back(node->left);
                }
                if(node->right){
                    myq.push_back(node->right);
                }
                if(i==q_size-1){
                    result.push_back(node->val);
                }
                myq.pop_front();
            }
        }
        return result;
        
    }
};
