/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
       int minDiff = INT_MAX;
       stack<TreeNode*> st;
       TreeNode *prev = nullptr; 
       while(root || !st.empty())
       {
           if(root) {
               st.push(root);
               root = root->left;
           }else {
               root = st.top(); st.pop();
               if(prev) {
                   minDiff = min(minDiff, abs(prev->val-root->val));
               }
               prev = root;
               root = root->right;
           }
           
       }
       return minDiff; 
        
        
    }
};