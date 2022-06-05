#if 0
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
#endif

class Solution {
public:
    /* Bottom-Up */
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[0]=0;
        dp[1] = nums[0];
        if(n==1)
            return dp[n];
        
        dp[2] = max(nums[0], nums[1]);
        
        for(int i=3; i<=n; i++) {
            dp[i] = max((dp[i-2]+nums[i-1]), dp[i-1]);
        }
        return dp[n];
        
    }
};