class Solution {
    struct Node {
        int x, y, k, pathLen;
        Node (int X, int Y, int K, int L) : x(X), y(Y), k(K), pathLen(L)  {}
    };
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    queue<Node> q;
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int minPath = INT_MAX;
        int m = grid.size(), n = grid[0].size();
        if(grid[0][0]==1 && k<1) return -1;
        
        vector<vector<int>> visited(m, vector<int>(n, -1));
        grid[0][0]==1 ?  q.push(Node(0,0,k-1,0)) : q.push(Node(0,0,k,0));
        visited[0][0] = q.front().k;
        int count = 0;
        while(!q.empty()) {
            int level = q.size();
            for(int i=0; i<level; i++) {
                auto node = q.front(); q.pop();
                if(node.x== m-1 && node.y==n-1) {
                    minPath = min(node.pathLen, minPath);
                }
                
                for(int j=0; j<4; j++) {
                    int new_x = node.x + dirs[j][0];
                    int new_y = node.y + dirs[j][1];
                    if(new_x<0 || new_x>=m || new_y<0 || new_y>=n || visited[new_x][new_y]>=node.k ||
                      (grid[new_x][new_y]==1 && node.k==0)) {
                         continue;
                    }
    
                    Node newN = Node(new_x, new_y, node.k, node.pathLen+1);
                    if(grid[new_x][new_y]==1)
                        newN.k--;
                    visited[new_x][new_y] = newN.k;
                    q.push(newN);
                } // end of dirs
            } // end of level
            count++;
            
        }
        // cout<<"total levels: "<<count<<endl;
        return minPath==INT_MAX ? -1 : minPath;
    }
};