class Solution {
    map<int, vector<int>> adjList;
public:
    void buildGraph(int n, vector<vector<int>>& edges) {
        for(int i=0; i<n; i++) adjList[i] = {};
        for(auto e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
    }
    
    bool DFS(int src, int dest, vector<bool> &visited) {
        if(visited[src]) return false;
        if(src == dest) return true;
        
        visited[src] = true;
        for(auto u : adjList[src]) {
            if(!visited[u]) {
                bool rc = false;
                rc = rc || DFS(u, dest, visited);
                if(rc) return true;
            }
        }
        return false;
        
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        buildGraph(n, edges);
        
        vector<bool> visited(n, false);
        return DFS(source, destination, visited);
        
        
    }
};