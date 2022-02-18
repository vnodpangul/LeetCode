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

    int helper(TreeNode *current)
    {
        if(!current) return -1;
        
        if(current && !current->left && !current->right) {
            mp[0].push_back(current->val);
            return 0;
        }
        
        int h = 1 + max(helper(current->left), helper(current->right));
        mp[h].push_back(current->val);
        return h;
        
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(root == nullptr)
            return rc;
        
        helper(root);
        rc.resize(mp.size());
        for(auto elem : mp) {
            rc[elem.first] = elem.second;
        }
        
        return rc;
    }
    private:
        vector<vector<int>> rc;
        map<int, vector<int>>  mp;
};