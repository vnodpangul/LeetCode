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
     vector<vector<int>>  res;
public:
    int getHeight(TreeNode *root) {
        if(root==nullptr) return -1;
        int level = 1 + max(getHeight(root->left), getHeight(root->right));
        if(res.size()<level+1) res.push_back({});
        
        res[level].push_back(root->val);
        return level;
        
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(root==nullptr) return res;
        getHeight(root);
        
        return res;
    }
};