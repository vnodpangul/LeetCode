/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> newNodes;
    
public:
    
    void DFS(Node *root, Node *newRoot) {

        for(auto u : root->neighbors) {
            
            Node *n = nullptr;
            if(newNodes[u->val]==nullptr)  {
                n = new Node(u->val);
                newNodes[u->val] = n;
                newRoot->neighbors.push_back(n);

                DFS(u, n);
            } else {
                 n = newNodes[u->val];
                 newRoot->neighbors.push_back(n);
            }
 
        }
        
    }
    
    
    Node* cloneGraph(Node* node) {
        
        if(node == nullptr) return nullptr;
        
        Node *newRoot = new Node(node->val);
        newNodes[node->val] = newRoot;
        
        DFS(node, newRoot);
        
        return newRoot;
        
    }
};

// [[2,4],[1,3],[2,4],[1,3]]
/*
    1-->2,4
    2-->1,3
    3-->2,4
    4-->1,3

*/