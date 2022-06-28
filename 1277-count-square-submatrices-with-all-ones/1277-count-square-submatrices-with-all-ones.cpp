class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n,0));
        int res = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 || j==0)
                    dp[i][j] = matrix[i][j];
                else if(matrix[i][j]==1) {
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                    
                }
                res += dp[i][j];
            }
        }
        return res;
        
    }
};

/*
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]

[
  [0,1,1,1], // 3
  [1,1,2,2], // 6
  [0,1,2,3] // 6
]

// 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
[
  [1,0,1], // 2
  [1,1,0], // 2
  [1,2,0] //3
]
*/