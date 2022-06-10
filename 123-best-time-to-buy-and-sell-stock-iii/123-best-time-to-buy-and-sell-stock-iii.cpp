#if 0
/* Time Limit exeeds  TC: O(Kx No.OfDays x No.OfDays ) */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int n = prices.size();
        int k = 2;
        if(n<k) return 0;
        
        vector<vector<int>> dp(k+1, vector<int>(n, 0));
        
        for(int i=1; i<=k; i++) {
            for(int j=1; j<n; j++) {
                
                int NoTransMax = dp[i][j-1];
                int maxDiff = INT_MIN;
                for(int m=0; m<j; m++) {
                    maxDiff = max(maxDiff, ((prices[j]-prices[m])+dp[i-1][m]));
                }
                dp[i][j] = max(NoTransMax, maxDiff);
                
                
            }
        }
        
        return dp[k][n-1];
    }
};
#endif

#if 1
/* Time Limit exeeds  TC: O(Kx No.OfDays x No.OfDays ) */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k=2;
        if(k==0 || prices.size()==0)
            return 0;
        
        int n = prices.size();
        if(n<k) return 0;
        
        vector<vector<int>> dp(k+1, vector<int>(n, 0));
        
        for(int i=1; i<=k; i++) {
            int maxDiff = -prices[0];
            for(int j=1; j<n; j++) {
                
                int NoTransMax = dp[i][j-1];
                dp[i][j] = max(NoTransMax, maxDiff + prices[j]);
                maxDiff = max(maxDiff, dp[i-1][j]-prices[j]);
                
                
            }
        }
        
        return dp[k][n-1];
    }
};
#endif