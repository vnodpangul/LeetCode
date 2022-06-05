class Solution {
public:
    // [1,2,3,1]
    
    int helper(vector<int> &nums, int i, map<int, int> &dp) {
        if(dp.count(i))
            return dp[i];
        else if(i==0)
            return dp[i]=nums[i];
        else if(i==1)
            return dp[i] = max(nums[i], nums[i-1]);
        else
            return dp[i] = max( (nums[i]+helper(nums, i-2, dp)), helper(nums, i-1, dp) ); // 0+
        
    }
    
    int rob(vector<int>& nums) {
        /* Top Down implementation */
        
        int res = INT_MIN;
        int n = nums.size();
        map<int, int> dp;
        
        res = helper(nums, nums.size()-1, dp);
        return res;
        
    }
};