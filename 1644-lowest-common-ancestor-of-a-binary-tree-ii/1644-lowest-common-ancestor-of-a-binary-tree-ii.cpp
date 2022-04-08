/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr)
            return nullptr;
        else if(root->val == p->val || root->val == q->val) {
            return root;
        }    
        else {
            TreeNode *lh = helper(root->left, p, q);
            TreeNode *rh = helper(root->right, p, q);
            if(lh && rh) return root;
            return lh==nullptr ? rh : lh;
        }
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *rc = helper(root, p, q);
        if(rc == p) {
            return helper(p, q, q) != nullptr ? rc : nullptr;
        }
        else if(rc == q) {
            return helper(q, p, p) != nullptr ? rc : nullptr;
        }
        return rc;
        
        
    }
};