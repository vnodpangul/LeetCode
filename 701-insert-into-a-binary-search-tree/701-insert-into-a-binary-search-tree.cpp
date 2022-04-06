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
    
    void helper(TreeNode *root, int val, bool leftDir, TreeNode *prev) {
        
        if(root == nullptr && prev == nullptr)
            return;
        if(root == nullptr)
        {
            if (leftDir)
                prev->left = new TreeNode(val);
            else 
                prev->right = new TreeNode(val);
            return;
        }
        
        if(val < root->val)
            return helper(root->left, val, true, root);
        if(val > root->val)
            return helper(root->right, val, false, root);
            
        
        
        
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        bool leftDir = true;
        TreeNode *prev = nullptr;
        if(root==nullptr) return new TreeNode(val);
        helper(root, val, leftDir, prev);
        return root;
        
    }
};