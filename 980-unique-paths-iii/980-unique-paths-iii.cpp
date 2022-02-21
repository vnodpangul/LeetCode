class Solution {
public:
    
    void DFS(vector<vector<int>>& grid, int x, int y, int &res, int empty)
    {
        if(x<0 || x>=grid.size() || y<0 || y>= grid[0].size() || grid[x][y]<0)
            return;

        if(grid[x][y]==2) {
            if(empty==0)
                res++;
            return;
        }
        
        grid[x][y] = -2;
        empty--;
        DFS(grid, x+1, y, res, empty);
        DFS(grid, x-1, y, res, empty);
        DFS(grid, x, y+1, res, empty);
        DFS(grid, x, y-1, res, empty);
        grid[x][y] = 0;
        empty++;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        
        int empty=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
               if(grid[i][j]==1) {
                    startx = i;
                    starty = j;
                }else if(grid[i][j] != -1){
                    empty++;
                }
            }
        }
        
        int res=0;
      
        // cout<<"Empty: "<<empty<<endl;
        DFS(grid, startx, starty, res,  empty);
        return res;
    }
    
    private:
        int endx=0, endy=0, startx=0, starty=0;
};