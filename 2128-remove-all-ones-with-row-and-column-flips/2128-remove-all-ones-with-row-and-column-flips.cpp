class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Flip first row column 1s
        for(int j=0; j<n; j++) {
            if(grid[0][j] != 0) {
                
                // Flip that column rows
                for(int i=0; i<m; i++)
                    grid[i][j] = !grid[i][j];
            }
        }
        
        for(int i=1; i<m; i++) {
            int sum = 0;
            for(int j=0; j<n; j++)
                sum += grid[i][j];
            
            if(sum!=0 && sum !=n)
                return false;
        }
        return true;
        
    }
};