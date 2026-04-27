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
    bool rootNode(TreeNode* root, TreeNode* subRoot){
         if(!root) return false;

         if(root->val== subRoot->val){
            //recurse with subRoot
            if (checkSubtree(root->left, subRoot->left) && checkSubtree(root->right, subRoot->right)){
                return true;
            }

        }
        bool left = rootNode(root->left, subRoot);
        bool right = rootNode(root->right, subRoot);
        return left || right;

    }
    bool checkSubtree(TreeNode *root2, TreeNode* subRoot){
  
        if(!root2 && !subRoot){
            return true;
        }
        if(!root2 || !subRoot) return false;
        if(root2->val != subRoot->val){
            return false;
        }
        return checkSubtree(root2->left, subRoot->left) && checkSubtree(root2->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        ///first we need to go to that root node that is subroot
        return rootNode(root, subRoot);

    }
};
