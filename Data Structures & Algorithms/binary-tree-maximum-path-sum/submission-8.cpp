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
    int res = INT_MIN;
public:
    int maxHelper(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = maxHelper(root->left);
        int right = maxHelper(root->right);
        ///now lets check max of both the left and right
        int max_num = max({left, right, 0})+ root->val;
        res = max(res,max(left,0)+ max(right,0) + root->val);
        return max_num;  



    }
    int maxPathSum(TreeNode* root) {
        int maxer= maxHelper(root);
        cout << maxer <<endl;
        return res;
        

    }
};
