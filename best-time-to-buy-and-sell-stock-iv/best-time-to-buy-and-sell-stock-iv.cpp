class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        if(k==0 || n<k)
            return 0;
        
        vector<vector<int>> dp(k+1, vector<int>(n,0));
        for(int i=1; i<=k; i++) {
            int maxDiff = -prices[0];
            for(int j=1; j<n; j++) {
                int noTransDiff = dp[i][j-1];
                dp[i][j] = max(noTransDiff, maxDiff+prices[j]);
                maxDiff = max(maxDiff, dp[i-1][j]-prices[j]);
                
            }
            
        }
        
        return dp[k][n-1];
        
    }
};

// maxProfit = 6-2 + 3-0
// buy = 0
// [3,2,6,5,0,3]