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
    int idx = 0; int res = 0;
    void helper(TreeNode *root, int k, int& idx)
    {
        if(root==nullptr)
            return;
        helper(root->left, k, idx);
        ++idx;
        // cout<<idx<<": "<<root->val<<endl;
        if(idx==k){
            res = root->val;
            return;
        } 
        helper(root->right, k, idx);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr)
            return -1;
        helper(root, k, idx);
        return res;
    }
};