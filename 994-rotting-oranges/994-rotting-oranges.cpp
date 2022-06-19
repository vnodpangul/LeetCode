class Solution {
    int fresh=0, total = 0;
    vector<vector<int>> dirs = {
        {0,1}, {0,-1}, {1,0}, {-1,0}  
    };
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==2) {
                    q.push(make_pair(i,j));
                }else if(grid[i][j] ==1)
                {
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        
        int len = 1;
        while(!q.empty()) {
           
            int level = q.size();
            for(int i=0; i<level; i++) {
                auto dir = q.front(); q.pop();
                int x = dir.first, y =dir.second;
                for(int j=0; j<dirs.size(); j++) {
                    int new_x = x + dirs[j][0];
                    int new_y = y + dirs[j][1];
                    if(new_x<0 || new_y<0 || new_x>=m || new_y>=n ||
                       grid[new_x][new_y]==2 || grid[new_x][new_y]==0)
                        continue;
                    
                    grid[new_x][new_y] = 2;
                    fresh--;
                    if(fresh==0) return len;
                    q.push(make_pair(new_x, new_y));
                }
                
            }
            len++;
        }
        
        return -1;
    }
};