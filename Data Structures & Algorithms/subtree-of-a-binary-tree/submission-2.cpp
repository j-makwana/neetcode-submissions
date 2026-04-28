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
        if(!subRoot){
            return true;
        }
        if(!root){
            return false;

        }
        //now i know that root is there and subroot too
        if(checkSubtree(root, subRoot)){
            return true;
        }
        return rootNode(root->left, subRoot) || rootNode(root->right, subRoot);
        

    }
    bool checkSubtree(TreeNode *root2, TreeNode* subRoot){
        if(!root2 && !subRoot){
            return true;
        }
        if(root2 && subRoot && root2->val == subRoot->val){
            return (checkSubtree(root2->left, subRoot->left) && checkSubtree(root2->right, subRoot->right));
        }
        return false;
      
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        ///first we need to go to that root node that is subroot
        return rootNode(root, subRoot);

    }
};
