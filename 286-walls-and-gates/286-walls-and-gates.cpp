class Solution {
public:
    
    void bfs(vector<vector<int>>& rooms, int m, int n, queue<pair<int,int>> &q)
    {
       
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int level = 1;
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++) {
                auto elem = q.front(); q.pop();
                for(int j=0; j<dirs.size(); j++) {
                    int new_x = elem.first + dirs[j][0];
                    int new_y = elem.second + dirs[j][1];
                    
                    if(new_x<0 || new_x>=m || new_y<0 || new_y>=n || 
                       rooms[new_x][new_y]==-1 || rooms[new_x][new_y]!=INT_MAX)
                    {
                        continue;
                    }
                    q.push({new_x, new_y});
                    rooms[new_x][new_y] = level;
                }
            }
            level++;
        }
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
       int m = rooms.size();
        if(m==0) return;
        int n = rooms[0].size();
        
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(rooms[i][j]==0) {
                    q.push({i,j});
                } 
            }
        }
        
        bfs(rooms, m, n, q);
        
        
    }
    
    private:
        vector<vector<int>> dist_dp;
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
};
