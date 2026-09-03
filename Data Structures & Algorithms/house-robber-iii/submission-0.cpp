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
    int rob(TreeNode* root) {
        //at ever node you have 3 options,
        //take the left, take the right, oe use the node.
        //1 vs 4 vs 0, take 4? if node is taken then you can take the children
        ///as simple as that
        ///
        pair<int,int> myAns = rob2(root);
        return max(myAns.first, myAns.second);
        
    }
    pair<int,int> rob2(TreeNode* root){
        if(root == nullptr){
            return {0,0};
        }
        pair<int,int> left = rob2(root->left);
        pair<int,int> right = rob2(root->right);

        int withRoot = root->val + left.second + right.second;
        int withoutRoot = max(left.first, left.second) + max(right.first, right.second);
        return {withRoot, withoutRoot};
    }

};