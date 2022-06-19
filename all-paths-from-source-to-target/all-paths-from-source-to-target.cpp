class Solution {
    vector<vector<int>> res;
public:
    
    void DFS(int s, int d, vector<int> &tmp, vector<bool>&visited, vector<vector<int>>& graph)
    {
        if(visited[s]) return;
        
        visited[s] = true;
        tmp.push_back(s);
        
        if(s==d) res.push_back(tmp);

        for(auto u: graph[s]) {
            if(!visited[u]) {
                DFS(u, d, tmp, visited, graph);
            }
            
        }
        visited[s] = false;
        tmp.pop_back();
        
    }
    
    void BFS(int s, int d, vector<bool>&visited, vector<vector<int>>& graph)
    {
        queue<vector<int>> q;
        q.push({s});
        while(!q.empty()) {
            auto path = q.front(); q.pop();
            int node = path[path.size()-1];
            // cout<<
            if(node == d) res.push_back(path);
            // visited[node] = true;
            for(int u : graph[node]) {
                // if(!visited[u]) {
                    path.push_back(u);
                    q.push(path);
                    path.pop_back();
                // }
            }
        }
        
        
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0, dest = graph.size()-1;
        
        vector<int> tmp; vector<bool> visited(graph.size(), false);
        // DFS(src, dest, tmp, visited, graph);
        BFS(src, dest, visited, graph);
        
        return res;
    }
};