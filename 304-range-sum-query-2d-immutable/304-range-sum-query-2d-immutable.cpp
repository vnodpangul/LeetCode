class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        dp.resize(m+1, vector<int>(n+1, 0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                dp[i+1][j+1] = matrix[i][j] + dp[i+1][j] + dp[i][j+1] - dp[i][j];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        
        return dp[r2+1][c2+1] - dp[r2+1][c1] - dp[r1][c2+1] + dp[r1][c1];
        
    }
private:
    int m, n;
    vector<vector<int>> dp;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */