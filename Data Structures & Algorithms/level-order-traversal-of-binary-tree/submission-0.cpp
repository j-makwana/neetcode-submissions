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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return {};
        }
        deque<TreeNode*> myq;
        myq.push_back(root);
        while(!myq.empty()){
            vector<int> result;
            int curLevel = myq.size();

            for(int i = 0; i<curLevel; i++){
                TreeNode* node = myq.front();
                if(node->left){
                    myq.push_back(node->left);
                }
                if(node->right){
                    myq.push_back(node->right);
                }

                result.push_back(node->val);
                ///process these nodes
                myq.pop_front();
            }


            if(!result.empty()){
                ans.push_back(result);
            }

        }
        return ans;
        
    }
};
