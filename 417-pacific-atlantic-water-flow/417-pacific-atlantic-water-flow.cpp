class Solution {
    int m, n;
    vector<vector<int>> commonVisited, heights;

    struct Node {
        int x, y;
        Node (int a, int b) : x(a), y(b) {}
    };
    vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    
    void BFS(queue<Node> &q, vector<vector<bool>>& visited)
    {
        visited.resize(m, vector<bool>(n, false));
        while(!q.empty())
        {
            auto node = q.front(); q.pop();
            visited[node.x][node.y] = true;
            commonVisited[node.x][node.y]++;
            for(auto d : dirs)
            {
                int newx = d[0]+node.x;
                int newy = d[1]+node.y;
                if(newx<0 || newy<0 || newx>=m || newy>=n || visited[newx][newy] || 
                   heights[newx][newy]<heights[node.x][node.y])
                {
                    continue;
                }
                q.push(Node(newx, newy));
            }
        }
    }
    
    void construct(vector<vector<int>>& h)
    {
        heights = h;
        m = heights.size();
        n = heights[0].size();
        commonVisited.resize(m, vector<int>(n,0));
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        construct(heights);
        
        queue<Node> q1, q2;
        for(int j=0; j<n; j++)
        {
            q1.push(Node(0, j));
            q2.push(Node(m-1, j));
        }
        for(int i=0; i<m; i++)
        {
            q1.push(Node(i,0));
            q2.push(Node(i,n-1));
        }
        
        vector<vector<bool>> avisited, pvisited;
        BFS(q1, pvisited);
        BFS(q2, avisited);
        
        vector<vector<int>> res;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(avisited[i][j] && pvisited[i][j])
                {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};