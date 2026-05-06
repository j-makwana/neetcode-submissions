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
    TreeNode* helper(span<const int> preorder, span<const int> inorder){
          if(preorder.empty() || inorder.empty()) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        int mid = (it==inorder.end()) ? -1 : it-inorder.begin();

        root->left = helper(preorder.subspan(1, mid), inorder.subspan(0, mid));
        root->right = helper(preorder.subspan(mid+1), inorder.subspan(mid+1));
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder);
      
        
    }
};
