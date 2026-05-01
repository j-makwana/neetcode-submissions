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
    int goodies(TreeNode* root, int pathHighest){
        
        if(!root){
            return 0;
        }
        int count = 0;
        if(root->val>= pathHighest){
            pathHighest = root->val;
            count = 1;
        }
        return count + goodies(root->left, pathHighest) + goodies(root->right, pathHighest);
        
    }
    int goodNodes(TreeNode* root) {
        return goodies(root, root->val);
        
    }
};
