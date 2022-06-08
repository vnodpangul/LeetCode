class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        
        vector<int> dp(n, 1);
        int res = 1;
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                
                if(nums[j]>=nums[i])
                    continue;
                else {
                    dp[i] = max(dp[i], 1+dp[j]);
                    res = max(res, dp[i]);
                }
                
            }
        }
        
        return res;
        
    }
};

// [ 10 | 9 | 2 | 5 | 3 | 7 ]
// [ 1  | 1 | 1 | 2 | 2 | 3 ]