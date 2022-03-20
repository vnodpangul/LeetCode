class Solution {
public:
    
    int DFS(vector<vector<int>>& grid, int n,  vector<vector<vector<vector<int> >>> &visited, int r1, int c1, int r2, int c2)
    {
        if(r1>=n || c1>=n || r2>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
        {
            return INT_MIN;
        }
        if(visited[r1][c1][r2][c2] != -1) {
            return visited[r1][c1][r2][c2];
        }
        if(r1==n-1 && c1==n-1) {
            return grid[r1][c1];
        }
        if(r2==n-1 && c2==n-1) {
            return grid[r2][c2];
        }
        int cherryCount = 0;
        if(r1==r2 && c1==c2) {
            cherryCount = grid[r1][c1];
        }else {
            cherryCount = grid[r1][c1] + grid[r2][c2];
        }
        
        int maxRc = max(
                        max(DFS(grid, n, visited, r1+1, c1, r2+1, c2),  DFS(grid, n, visited, r1+1, c1, r2, c2+1)),
                        max(DFS(grid, n,visited,  r1, c1+1, r2+1, c2), DFS(grid, n, visited, r1, c1+1, r2, c2+1))
                    );
        visited[r1][c1][r2][c2] = cherryCount + maxRc;
        
        return visited[r1][c1][r2][c2];
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int> >>> visited(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1) )));
        return max(0, DFS(grid, n, visited, 0, 0, 0, 0));
    }
};