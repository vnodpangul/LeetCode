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
private:
    int maxD = 0;
public:
    int diameterOfBinaryTreeHelper(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int lh = diameterOfBinaryTreeHelper(root->left);
        int rh = diameterOfBinaryTreeHelper(root->right);
        maxD = max(maxD, lh+rh);
        
        return 1+max(lh,rh);
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        diameterOfBinaryTreeHelper(root);
        return maxD;
    }
};