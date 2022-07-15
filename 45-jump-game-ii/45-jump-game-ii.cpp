class Solution {
public:
    int jump(vector<int>& nums) {
     
        int jumps = 0;
        int curFarthest = 0, start = 0, end=0;
        for(int i=0; i<nums.size()-1; i++)
        {
            curFarthest = max(curFarthest, nums[i]+i);
            if(i==end)
            {
                jumps++;
                end = curFarthest;
            }
        }
        return jumps;
    }
};