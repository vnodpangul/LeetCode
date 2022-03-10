class Solution {
public:
    
    void bfs(vector<vector<int>>& grid, int m, int n, int x, int y) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push({x,y});
        int level = 1;
        // visited[x][y] = true;
        
        while(!q.empty())
        {
            
            int size = q.size();
            for(int k=0; k<size; k++) {
                auto elm = q.front(); q.pop();

                for(int i=0; i<dirs.size(); i++)
                {
                    int new_x = elm.first +dirs[i][0];
                    int new_y = elm.second +dirs[i][1];
                    if(new_x<0 || new_y<0 || new_x>=m || new_y >=n ||
                      visited[new_x][new_y] || grid[new_x][new_y] != 0) {
                        continue;
                    }
                        
                    q.push({new_x, new_y});
                    visited[new_x][new_y] = true;
                    dist_dp[new_x][new_y] += level;
                    reach_count_dp[new_x][new_y]++;
                }
            }
            level++;
        }
    }
    
    
    int shortestDistance(vector<vector<int>>& grid) {
       int m = grid.size();
       if(m==0) return 0;
       int n = grid[0].size();
       
        dist_dp.resize(m, vector<int>(n,0));
        reach_count_dp.resize(m, vector<int>(n,0));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    bfs(grid, m, n, i, j);
                    total_buildings++;
                }
            }
        }
        
         int minDist = INT_MAX;
         for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==0 && reach_count_dp[i][j]==total_buildings) {
                    minDist = min(minDist, dist_dp[i][j]);
                }
            }
         }
        
        return minDist == INT_MAX ? -1 : minDist;        
    }
    
    private:
        vector<vector<int>> dist_dp, reach_count_dp;
        int total_buildings = 0;
        vector<vector<int>> dirs = {{0,1}, {0, -1}, {1,0}, {-1,0}};
};