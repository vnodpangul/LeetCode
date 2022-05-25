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
    int helper(TreeNode *root) {
        if(!root)
            return 0;

        
        int lsum = max(0, helper(root->left));
        int rsum = max(0, helper(root->right));

        int sum = root->val +lsum + rsum;
        maxSum = max(maxSum, sum);
        
        return root->val + max(lsum,rsum);
    }
    
    
    int maxPathSum(TreeNode* root) {
        if(!root->left && !root->right)
            return root->val;
        

        helper(root);
        return maxSum;
    }
private:
    int maxSum = INT_MIN;
};