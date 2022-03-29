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
    int successor(TreeNode *root)
    {
        TreeNode *current = root->right;
        while(current->left) current = current->left;
        return current->val;
    }
    int predecessor(TreeNode *root) {
        TreeNode *current = root->left;
        while(current->right) current = current->right;
        return current->val;
    }
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        
        if(key>root->val) {
            root->right = deleteNode(root->right, key);
        }else if(key<root->val) {
            root->left = deleteNode(root->left, key);
        }else {
            if(root->left == nullptr && root->right==nullptr) root = nullptr;
            else if(root->right != nullptr) {
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            }else {
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
};