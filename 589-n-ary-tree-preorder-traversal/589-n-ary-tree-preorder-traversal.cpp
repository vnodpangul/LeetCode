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
    void helper(Node *root, vector<int> &rc)
    {
        if(root==nullptr) return;
        
        rc.push_back(root->val);
        for(auto node: root->children) {
            helper(node, rc);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> rc;
        helper(root, rc);
        return rc;
    }
};