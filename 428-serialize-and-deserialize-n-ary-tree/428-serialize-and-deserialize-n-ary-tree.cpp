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

class Codec {
public:
    
    string sHelper(Node *root) 
    {
        if(!root) return "#";
        
        string s="";
        s += to_string(root->val) + " " + to_string(root->children.size()) + " ";
        for(auto child: root->children) 
        {
            s += sHelper(child);
        }
        return s;
    }
    
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        return sHelper(root);
    }
    
    Node* dHelper(istringstream &iss) {
        string val, size;
        iss>>val;
        if(val == "#") return nullptr;
        
        Node *root = new Node(stoi(val));
        iss>>size;
        for(int i=0; i<stoi(size); i++) {
            root->children.push_back(dHelper(iss));
        }
        return root;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream iss(data);
        return dHelper(iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));