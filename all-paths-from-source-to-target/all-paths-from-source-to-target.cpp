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
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0, dest = graph.size()-1;
        
        vector<int> tmp; vector<bool> visited(graph.size(), false);
        DFS(src, dest, tmp, visited, graph);
        
        return res;
    }
};