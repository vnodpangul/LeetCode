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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1, st2;
        vector<int> rc;
        
        while(root1 || root2 || !st1.empty() || !st2.empty())
        {
            if(root1 || root2) {
                if(root1) {
                    st1.push(root1);
                    root1 = root1->left;
                }
                if(root2) {
                    st2.push(root2);
                    root2 = root2->left;
                }
            }else {
                TreeNode *prev = nullptr;
                if(!st1.empty() && !st2.empty())
                {
                   if(st1.top()->val < st2.top()->val) {
                       prev = st1.top();
                       st1.pop();
                       root1 = prev->right;
                   }else {
                       prev = st2.top();
                       st2.pop();
                       root2 = prev->right;
                   }
                   
                    
                }else {
                    
                    prev = st1.empty() ? st2.top() : st1.top();
                    st1.empty() ? root2 = prev->right : root1 = prev->right;
                    st1.empty() ? st2.pop() : st1.pop();
                    
                }
                rc.push_back(prev->val); 
            }
            
        } // End of while loop
         return rc;
        
    }
};