/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "";
        
        string res = to_string(root->val) + " " + serialize(root->left) + serialize(root->right);

        return res;
    }

    TreeNode* helper(vector<string> &tokens, int &idx, int min, int max)
    {
        if(idx>=tokens.size()) return nullptr;
        int val = stoi(tokens[idx]);
        if(val<min || val>max) return nullptr;
        
        idx++;
        TreeNode *root = new TreeNode(val);
        root->left = helper(tokens, idx, min, val);
        root->right = helper(tokens, idx, val, max);
        
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        // char delim = ' ';
        string token="";
        vector<string> tokens;

        // while(getline(iss, token, delim)) {
        //     if(token == " " || token =="") continue;
        //     tokens.push_back(token);
        // }
        while(iss>>token) tokens.push_back(token);
        int idx = 0;
        return helper(tokens, idx, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;