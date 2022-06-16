class Solution {
    map<int, vector<int>> adjList;
public:
    
    bool DFS(int s, int d, vector<bool> &visited)
    {
        if(s==d && adjList[s].size() ==0) return false;
        if ((s!=d && adjList[s].size()==0) || visited[s]) return true;
        
        
        visited[s] = true;
        for(auto u : adjList[s]) {
            bool rc = false;
            rc = rc || DFS(u, d, visited); // If True: One path doesn't complete on destination
            if(rc) return true; // If True: not all path ends on destination 
        }
        visited[s] = false;
        return false;
    }
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i=0; i<n; i++)
            adjList[i] = {};
        for(auto e : edges)
            adjList[e[0]].push_back(e[1]);
        
        if(adjList[destination].size()>0) return false;
        vector<bool> visited(n, false);
        return !DFS(source, destination, visited);
        
    }
};

// 4
// [[0,1],[0,2],[1,3],[2,3]]
// 0
// 3
// 0-->1,2
// 1-->3
// 2-->3
// 3--