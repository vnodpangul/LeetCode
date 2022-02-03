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
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>  rc;
        if(root == nullptr) return rc;
        
        queue<Node*> q;
        q.push(root);
        int idx = 0;
        while(!q.empty()) 
        {
            int size = q.size();
            rc.push_back({});
            // rc[idx].resize(size);
            // rc.emplace_back();
            for(int i=0; i<size; i++) {
                Node *current = q.front(); q.pop();
                rc[idx].push_back(current->val);
                
                for(auto node: current->children) {
                    q.push(node);
                }
            }
            idx++;
        }
        return rc;
    }
};