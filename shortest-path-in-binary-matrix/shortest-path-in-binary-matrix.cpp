class Solution {
private:
    queue<pair<int, int>> q;
    vector<vector<int>> dirs = { {0,1}, {0,-1}, {1,0}, {-1,0}, 
                                 {1,1}, {-1,1}, {1,-1}, {-1,-1}
                               };
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return -1;
        q.push(make_pair(0,0));
        visited[0][0] = true;
        
        int len = 1;
        while(!q.empty()) {
            
            int level = q.size();
            for(int i=0; i<level; i++) {
                auto pt = q.front(); q.pop();
                
                int x = pt.first, y = pt.second;
                if(x== m-1 && y==n-1)  return len;
                
                for(int j=0; j<dirs.size(); j++) {
                    int new_x = x + dirs[j][0];
                    int new_y = y + dirs[j][1];
                    if(new_x<0 || new_x>=m || new_y<0 || new_y>=n
                        || visited[new_x][new_y] || grid[new_x][new_y]==1) {
                        continue;
                    }
                    q.push(make_pair(new_x, new_y));
                    visited[new_x][new_y] = true;
                } // End of Dirs
                
            } // End of Level
            len++;
        }
        return -1;
        
        
    }
};