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
    
    string sHelper(TreeNode *root)
    {
        if(root==nullptr) return "#";
        
        string str = "";
        str += to_string(root->val) + " " +
                sHelper(root->left) + " " +
                sHelper(root->right);
        
        return str;
        
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return sHelper(root);
    }
    
    TreeNode* dHelper(istringstream &iss) {
        string val;
        iss>>val;
        if(val=="#") return nullptr;
        
        TreeNode *root = new TreeNode(stoi(val));
        root->left = dHelper(iss);
        root->right = dHelper(iss);
        
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return dHelper(iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

// 2 1 # # 3 # #
// val = 2
//     root -> left = helper(1 # # 3 # #)
//         root -> left = helper(# # 3 # #)
//         root->right = helper(# 3 # #)
//     root->right = helper(3 # #)
//         root -> left = helper(# #)
//         root->right = helper(#)