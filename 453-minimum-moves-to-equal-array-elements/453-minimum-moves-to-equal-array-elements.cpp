class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int min = nums[0];
        for(int n : nums)
            if(n<min) min = n;
        
        int res = 0;
        for(int n : nums)
            res += (n-min);
        
        return res;
        
        
    }
};
