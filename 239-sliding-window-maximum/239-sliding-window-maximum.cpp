class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> rc;
        
        for(int i=0; i<nums.size(); i++) {
            while(!dq.empty() && dq.front()<=i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
            
            dq.push_back(i);
            
            if(i+1>=k) {
                rc.push_back(nums[dq.front()]);
            }
        }
        
        return rc;
    }
};


// [1,3,1,2,0,5]
// 3

// 3,1,2