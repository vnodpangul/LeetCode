class Solution {
public:
    
    void DFS(vector<vector<int>>& grid, int m, int n, int x, int y,
            int countZero, vector<vector<bool>> &visited, int &res)
    {
        if(x<0 || y<0 || x>=m || y>=n || grid[x][y] == -1 || 
          visited[x][y])
        {
            return;
        }
        
        if(grid[x][y] == 2) {
            if(countZero==0)
                res++;
            return;
        }
        visited[x][y] = true;
        --countZero;
        DFS(grid, m, n, x+1, y,  countZero, visited, res);
        DFS(grid, m, n, x-1, y, countZero, visited, res);
        DFS(grid, m, n, x, y+1, countZero, visited, res);
        DFS(grid, m, n, x, y-1, countZero, visited, res);
        visited[x][y] = false;
        ++countZero;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int start_x = -1, start_y = -1;
        int countZero = 1;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) {
                    start_x = i;
                    start_y = j;
                }else if(grid[i][j] == 0) {
                    countZero++;
                }
            }
        }
        
        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        DFS(grid, m, n, start_x, start_y, countZero, visited, res);
        return res;
        
    }
};