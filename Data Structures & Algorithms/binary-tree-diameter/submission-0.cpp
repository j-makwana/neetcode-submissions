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
    int helper(TreeNode* root, int *maxDiam){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        int left = helper(root->left, maxDiam);
        int right = helper(root->right, maxDiam);

        *maxDiam = max(*maxDiam, left+right);


        return max(left,right)+1;

    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiam = 0;
        helper(root, &maxDiam);
        return maxDiam;
    }
};
