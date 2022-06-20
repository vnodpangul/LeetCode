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
    bool preOrder(TreeNode *root, int findVal, string &path)
    {
        if(root == nullptr) return false;
        if(root->val == findVal) return true;
        if(root->left) {
            bool rc = rc || preOrder(root->left, findVal, path);
            if(rc) { path += "L"; return rc; }
        }
        if(root->right) {
            bool rc = rc || preOrder(root->right, findVal, path);
            if(rc) { path += "R"; return rc; }
        }
        return false;
    }
    
    bool find(TreeNode* n, int val, string &path) {
    if (n->val == val)
        return true;
    if (n->left && find(n->left, val, path))
        path.push_back('L');
    else if (n->right && find(n->right, val, path))
        path.push_back('R');
    return !path.empty();
  }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        if(root==nullptr) return "";
        string res, s_p, d_p;
        
        preOrder(root, startValue, s_p);
        preOrder(root, destValue, d_p);
        // find(root, startValue, s_p);
        // find(root, destValue, d_p);
        // cout<<s_p<<":"<<d_p<<endl;
        while(!s_p.empty() && !d_p.empty() && s_p.back()==d_p.back())
        {
            s_p.pop_back();
            d_p.pop_back();
        }
        
        return string(s_p.size(), 'U') + string(rbegin(d_p), rend(d_p));
    }
};