/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// head = [7,9,6,6,7,8,3,0,9,5], k = 5
    

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        unordered_map<int, ListNode*> prevMp;
        int idx = 1;
        ListNode *prev = nullptr, *current = head;
        
        while(current) {
            prevMp[idx++] = prev;
            prev = current;
            current = current->next;
        }
            int tmp =  prevMp[k] == nullptr ? head->val : prevMp[k]->next->val;
            int val = (prevMp[idx-k]==nullptr) ? head->val :  prevMp[idx-k]->next->val;
            
        if (prevMp[k]==nullptr) 
            head->val = val;
        else
            prevMp[k]->next->val = val;
            
        
            prevMp[idx-k]== nullptr ? head->val = tmp : prevMp[idx-k]->next->val = tmp;
        
        // prevMp[idx-k]->next->val = tmp;
        
        
        return head;
        
    }
};