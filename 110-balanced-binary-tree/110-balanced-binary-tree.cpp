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
    int helper(TreeNode *root, bool &rc)
    {
        if(root == nullptr)
            return 0;
        
        int lh = 1 + helper(root->left, rc); // 1
        int rh = 1 + helper(root->right, rc); // 1+1
        if(abs(lh-rh) > 1) {
            rc = false;
            return -1;
        }
        return max(lh, rh);
        
    }
    
    bool isBalanced(TreeNode* root) {
        bool rc = true;
        helper(root, rc);
        return rc;
    }
};