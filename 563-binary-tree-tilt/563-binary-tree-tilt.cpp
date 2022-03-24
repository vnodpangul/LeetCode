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
    int helper(TreeNode *root, int &sum)
    {
        if(!root) return 0;
        
        int lsum = helper(root->left, sum);
        int rsum = helper(root->right, sum);

        root->val = root->val+lsum+rsum;
        sum += abs(lsum-rsum);
        return root->val;
    }
    int findTilt(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return sum;
    }
};