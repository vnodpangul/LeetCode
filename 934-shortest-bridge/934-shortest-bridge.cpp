#define ID1 -1

class Solution {
     vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
     queue<pair<int,int>> q;
    
    
    void DFS(vector<vector<int>>& grid, int m, int n, int i, int j)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=1)
        {
            return;
        }
        // cout<<i<<":"<<j<<endl;
        q.push({i,j});
        grid[i][j] = ID1;
        for(auto d: dirs)
        {
            DFS(grid, m, n, i+d[0], j+d[1]);
        }
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();

        bool flag = false;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    DFS(grid, m, n, i, j);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(q.size()==0) return -1;
        
        int res = 0;
        while(!q.empty())
        {
            int level = q.size();
            for(int i=0; i<level; i++)
            {
                auto node = q.front(); q.pop();
                int x = node.first, y=node.second;
                for(auto d : dirs)
                {
                    int new_x = x+d[0], new_y=y+d[1];
                   
                    if(new_x>=0 && new_y>=0 && new_x<m && new_y<n && grid[new_x][new_y]!=ID1) 
                    {
                        if(grid[new_x][new_y]==1) { return res; }
                        grid[new_x][new_y] = -1;
                        q.push({new_x, new_y});
                    }
                }
            }
            res++;
        }
        
        return -1;
    }
};

