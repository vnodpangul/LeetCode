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
    int res = 0;
public:
    int getRightHeight(TreeNode *root)
    {
        if(root==nullptr) return 0;
        return 1 +  getRightHeight(root->right);
    }
     int getLeftHeight(TreeNode *root)
    {
        if(root==nullptr) return 0;
        return 1 + getLeftHeight(root->left);
    }
    
    int countNodes(TreeNode* root) {
        
        if(root==nullptr)
            return 0;
        
        int lh = getLeftHeight(root->left);
        int rh = getRightHeight(root->right);
        if(lh == rh)
        {
            // int tmp1 = pow(2,lh) - 1;
            // int tmp2 = (2<<lh)- 1;
            // cout<<lh<<":"<<tmp1<<":"<<tmp2<<endl;
            return (2<<lh)- 1;
        }else
        {
            return 1 + countNodes(root->left) + countNodes(root->right);
            
        }
        // return res;
    }
};