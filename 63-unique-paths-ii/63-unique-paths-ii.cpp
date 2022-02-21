class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m==0) return 0;
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int i=0, j=0;
        while(i<m && obstacleGrid[i][j] == 0) i++;
        while(i<m) {
            obstacleGrid[i][j] = 1;
            i++;
        }
        
        i=0;
        while(j<n && obstacleGrid[i][j] == 0) j++;
        while(j<n) {
            obstacleGrid[i][j] = 1;
            j++;
        }
        
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(obstacleGrid[i][j]==1) {
                    dp[i][j] = 0;
                }else if(i==0 || j==0 )
                {
                    dp[i][j] = 1;
                }
                else{
                     dp[i][j] =  dp[i-1][j] +  dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};