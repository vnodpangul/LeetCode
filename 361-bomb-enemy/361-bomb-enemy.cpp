class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int nrows = grid.size();
        if(nrows==0) return 0;
        int ncols = grid[0].size();
        
        int maxRes = 0;
        int rowKill = 0;
        vector<int> colkill(ncols, 0);
        
        for(int row=0; row<nrows; row++)
        {
            for(int col=0; col<ncols; col++)
            {
                // Search along the row, i.e. columns varies
                if(col==0 || grid[row][col-1]=='W')
                {
                    rowKill = 0;
                    for(int k=col; k<ncols; k++)
                    {
                        if(grid[row][k]=='E') rowKill++;
                        else if(grid[row][k]=='W') break;
                        
                    }
                    
                }
                   
                // Search along the column ( down) 
                if(row==0 || grid[row-1][col]=='W')
                {
                       colkill[col] = 0;
                       for(int k=row; k<nrows; k++)
                       {
                           if(grid[k][col]=='E')  colkill[col]++;
                           else if(grid[k][col]=='W') break;     
                       }
                }
                
                if(grid[row][col]=='0')
                {  
                    maxRes = max(maxRes, rowKill+colkill[col]);
                }
                
        }
    }
    return maxRes;
}
};
