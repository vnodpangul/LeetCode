class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = 0;
        for(int i=0; i<nums.size(); i++) {
            if(maxIdx<i) return false;
            int idx = i + nums[i];
            if(idx>maxIdx)  maxIdx = idx;
        }
        return true;
        
    }
};
