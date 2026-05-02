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
    int ans= 0;
    int j =0;

public:
    int ksmall(TreeNode* root, int k){
        if(!root){
            return 0;
        }
        int left= ksmall(root->left, k);
        j++;
         if(j ==k){
            ans = root->val;
        }
        int right = ksmall(root->right,k);
       
        return left + right;
        
    }
    int kthSmallest(TreeNode* root, int k) {
        ksmall(root, k);
        return ans;
        

    }
};
