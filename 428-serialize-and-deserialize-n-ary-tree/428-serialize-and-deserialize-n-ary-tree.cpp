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
    string serializeHelper(Node *root)
    {
        if(!root) {
            // cout<<"Hello"<<endl;
            return "#";

        }
        string res = "";
        res += to_string(root->val) + " " + to_string(root->children.size()) + " ";
        for(auto elem: root->children) {
            res += serializeHelper(elem);
        }
        return res;
        
    }
    
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res="";
        res = serializeHelper(root);
        // cout<<"Res: "<<res<<endl;
        return res;
    }
	
    Node* deserializeHelper(istringstream &iss) {
        string val, count;
        iss >> val;
        if(val == "#") return nullptr;
        
        Node *root = new Node(stoi(val));
        iss>>count;
        for(int i=0; i<stoi(count); i++) {
            root->children.emplace_back(deserializeHelper(iss));
            // root->children
        }
        
        return root;
    }
    
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));