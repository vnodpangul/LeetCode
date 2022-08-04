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
class Solution {
public:
    ListNode* mergeTwoList(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *current = dummy;
        while(l1!=nullptr && l2!=nullptr)
        {
            if(l1->val < l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if(l1) current->next = l1;
        if(l2) current->next = l2;
        
        return dummy->next;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        
        int interval = 1;
        while(interval<lists.size())
        {
            for(int i=0; i+interval<lists.size(); i+=(interval*2))
            {
                lists[i] = mergeTwoList(lists[i], lists[i+interval]); // 0,1 | 0,2
            }
            interval = interval*2;
        }
        return lists[0];
    }
};
