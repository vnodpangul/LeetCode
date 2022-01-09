class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = 0;
        int n = nums.size();
        vector<int> maxJump(n);
        
        
        for(int i=0; i<n; i++) {
           maxJump[i] = i+nums[i];
           maxIdx = max(maxJump[i], maxIdx);
           if(maxIdx<=i && i!=n-1) return false;
        }
        return true;
    }
};

// [3,2,1,0,4] maxIdx = 3
// [3,3,3,3]