#if 0
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        m = mat.size();
        n = mat[0].size();
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int minRow = row1<row2 ? row1:row2;
        int minCol = col1<col2 ? col1 : col2;
        int maxRow = row1>row2 ? row1 : row2;
        int maxCol = col1>col2 ? col1 : col2;
        
        int sum = 0;
        for(int i=minRow; i<=maxRow; i++)
        {
            for(int j=minCol; j<=maxCol; j++)
            {
                sum += mat[i][j];
            }
        }
        return sum;
        
    }
    
    private:
        vector<vector<int>> mat;
        int m, n;
};
#endif

#if 1

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        m = mat.size();
        n = mat[0].size();
        
       dp.resize(m+1, vector<int>(n+1, 0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
            {
              dp[i+1][j+1] = mat[i][j] + dp[i+1][j] + dp[i][j+1]-dp[i][j];
                
            }
        }
        
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        
        return dp[r2+1][c2+1] - dp[r2+1][c1] - dp[r1][c2+1] + dp[r1][c1] ;
        
    }
    
    private:
        vector<vector<int>> mat, dp;
        int m, n;
};

#endif

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

/*
r1,c1



            r2,c2
                        
for(int i=r1; i<=r2; i++)
    for(int j=c1; j<=c2; j++)
*/   