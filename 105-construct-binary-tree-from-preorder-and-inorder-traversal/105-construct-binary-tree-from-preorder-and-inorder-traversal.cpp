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
    TreeNode* helper(int &prIdx, vector<int> &Pre, vector<int> &In, int low, int high)
    {
        if(low>high) return nullptr;
        
        int num = Pre[prIdx];
        TreeNode *root = new TreeNode(num);
        prIdx++;
        root->left = helper(prIdx, Pre, In, low, InIdxMp[num]-1);
        root->right = helper(prIdx, Pre, In, InIdxMp[num]+1, high);
        return root; 
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++)
            InIdxMp[inorder[i]] = i;
        int prIdx = 0;
        return helper(prIdx, preorder, inorder, 0, inorder.size()-1);
    }
    private:
        map<int, int> InIdxMp;
};