/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==nullptr) return res;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            res.push_back({});
            for(int i=0; i<n; i++) {
                auto Node = q.front(); q.pop();
                res[res.size()-1].push_back(Node->val);
                
                for(auto child : Node->children)
                    q.push(child);
            }
        }
        return res;
    }
};