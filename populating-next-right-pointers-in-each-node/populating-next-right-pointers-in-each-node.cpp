/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<Node*> nextBatch;
            for(int i=0; i<size; i++) {
                Node *n = q.front(); q.pop();
                n->next = q.empty() ? nullptr : q.front();
                if(n->left) nextBatch.push_back(n->left);
                if(n->right) nextBatch.push_back(n->right);
            }
            for(auto n : nextBatch)
                q.push(n);
        }
        
        return root;
        
        
    }
};