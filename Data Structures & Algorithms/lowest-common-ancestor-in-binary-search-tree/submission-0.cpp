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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        if(p->val < root->val && q->val < root->val){
            ///means yuou go to the left subtree
            cout << "reached here" << endl;
            ans = lowestCommonAncestor(root->left, p, q);
        }
        if(p->val > root->val && q->val > root->val){
            ///you are too small, go right man
            ans = lowestCommonAncestor(root->right, p, q);
        }
        if(ans){
            return ans;
        }
        return root;

    }
};
