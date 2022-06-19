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

#if 0
    /* Time C: O(n) Space: O(n) */
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
#endif

#if 1
    /* Time C: O(n) Space: O(1) */
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        Node *leftMost = root;
        
        while(leftMost->left != nullptr) {
            Node *current = leftMost;
            while(current != nullptr) {
                current->left->next = current->right;
                
                if(current->next)
                    current->right->next = current->next->left;
                
                current = current->next;
                
            }
            leftMost = leftMost->left;
        }
        return root;  
    }
#endif
};