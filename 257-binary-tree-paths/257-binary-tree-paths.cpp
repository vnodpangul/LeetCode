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

    bool helper(TreeNode *root, vector<string> &rc, vector<string> &path)
    {
        if(root==nullptr)
            return true;
        
        path.push_back(to_string(root->val)+"->");
        bool left = helper(root->left, rc, path);
        bool right = helper(root->right, rc, path);
        if(left && right) {
            string tmp;
            for(auto &str : path)
                tmp+=str;
            
            tmp = tmp.substr(0, tmp.size()-2);
            rc.push_back(tmp); 
            path.pop_back();
            return false;
        }
        path.pop_back();
        return false;        
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> rc;
        vector<string> path;
        helper(root, rc, path);
        return rc;
    }
};