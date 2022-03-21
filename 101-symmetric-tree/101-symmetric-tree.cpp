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
    bool helper(TreeNode *lh, TreeNode *rh)
    {
        if(lh == nullptr || rh == nullptr) return lh==rh;
        if(lh->val != rh->val) return false;
        
        return helper(lh->left, rh->right) && helper(lh->right, rh->left); 
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr))
            return true;
        
        return helper(root->left, root->right);
    }
};