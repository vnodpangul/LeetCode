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
    bool helper(TreeNode *root, int target)
    {
        if(root == nullptr) return true;
        if(root->left == nullptr && root->right == nullptr && root->val == target)
        {
            // delete root;
            return true;
        }
        if(root->left == nullptr && root->right == nullptr)
           {
               return false;
           }
        
        
        bool rc1 = helper(root->left, target);
        bool rc2 = helper(root->right, target);
        if(rc1 && rc2) {
            // delete root;
            root->left = nullptr;
            root->right = nullptr;
            return root->val == target;
        }else if(rc1 || rc2)
        {
            if(rc1) root->left = nullptr; else root->right = nullptr;
            
        }
        return false;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool rc = helper(root, target);
        if(rc)
            root = nullptr;
        return root;
    }
};