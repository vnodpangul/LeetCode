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
    struct Node {
        TreeNode *root;
        int idx;
        Node(TreeNode *_root, int _idx) {
            root = _root;
            idx = _idx;
        }
    };
    
    void helper(queue<Node> q, map<int, vector<int>> &mp)
    {
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode *root = q.front().root; 
                int idx = q.front().idx;
                q.pop();
                mp[idx].push_back(root->val);
                
                if(root->left)
                    q.push({root->left, idx-1});
                if(root->right)
                    q.push({root->right, idx+1});
            }
        }
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> rc;
        if(root == nullptr) return rc;
        
        map<int, vector<int>> mp;
        queue<Node> q;
        
        q.push({root, 0});
        helper(q, mp);
        for(auto &elm: mp)
        {
            rc.push_back(elm.second);
        }
        return rc;
    }
};