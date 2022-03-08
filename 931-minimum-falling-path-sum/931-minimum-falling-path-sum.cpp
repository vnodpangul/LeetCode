class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return 0;
        if(matrix.size()==1 && matrix[0].size()==1) return matrix[0][0];
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
        for(int i=0; i<matrix[0].size(); i++) {
            dp[0][i] = matrix[0][i];
        }
        
        int rc = INT_MAX;
        for(int i=1; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                int minSum = INT_MAX;
                if(j==0)
                    minSum = min(dp[i-1][j], dp[i-1][j+1]);
                else if(j == matrix[0].size()-1)
                     minSum = min(dp[i-1][j], dp[i-1][j-1]);
                else
                     minSum = min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]));
                    
                dp[i][j] = matrix[i][j]+ min(dp[i][j], minSum);
                if(i == matrix.size()-1) {
                    rc = min(rc, dp[i][j]);
                }
            }
        }
        
        return rc;
        
    }
};