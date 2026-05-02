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
    vector<int> isitsorted(TreeNode* root){
        if(!root){
            return {};
        }
        vector<int> left=  isitsorted(root->left);
        left.push_back(root->val);
        vector<int> right = isitsorted(root->right);
        left.insert(left.end(), right.begin(), right.end());
        return left;
        



    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans = isitsorted(root);
        
        for(int i =1; i< ans.size();i++){
            if(ans[i]<= ans[i-1]){
                return false;
            }
        }

        return true;
        
    }
};
