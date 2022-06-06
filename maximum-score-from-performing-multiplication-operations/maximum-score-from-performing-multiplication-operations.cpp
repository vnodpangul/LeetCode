class Solution {
public:
    int helper(vector<int>& M, int idx, vector<int> &nums, int s, vector<vector<int>> &dp)
    {
        if(idx>=M.size())
            return 0;
        if(dp[idx][s] != INT_MIN)
            return dp[idx][s];
        int e = nums.size()-(idx-s)-1;
        int op1 = M[idx] * nums[s] + helper(M, idx+1, nums, s+1, dp);
        int op2 = M[idx] * nums[e] + helper(M, idx+1, nums, s, dp);
        return dp[idx][s] = max(op1, op2);
    }
    
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        vector<vector<int>> dp(1000+1, vector<int>(1000+1, INT_MIN) );
        return helper(multipliers, 0, nums, 0, dp);
        
    }
    private:
};
