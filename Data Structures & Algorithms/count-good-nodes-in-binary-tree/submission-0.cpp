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
    int ans =0;
public:
    void goodies(TreeNode* root, int pathHighest){
        if(!root){
            return;
        }
                cout <<root->val << " and " << pathHighest <<endl;

        if(root->val>= pathHighest){
            pathHighest = root->val;
            ans++;
        }
        goodies(root->left, pathHighest);
        goodies(root->right, pathHighest);
        return;
    }
    int goodNodes(TreeNode* root) {
        goodies(root, root->val);
        return ans;
    }
};
