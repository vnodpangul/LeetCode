class Solution {
    map<int, vector<int>> adjList;
    vector<int> inDegree;
public:
    void buildGraph(int n, vector<vector<int>>& prereq) {
        inDegree.resize(n, 0);
        for(auto c : prereq) {
            adjList[c[1]].push_back(c[0]);
            inDegree[c[0]]++;
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        buildGraph(n, prerequisites);
        queue<int> q;
        for(int i=0; i<n; i++)
            if(inDegree[i]==0) q.push(i);
        
        vector<int> res;
        vector<bool> visited(n, false);
        while(!q.empty())
        {
            int id = q.front(); q.pop();
            if(visited[id])
                return {};
            visited[id] = true;
            res.push_back(id);
            for(auto v : adjList[id]) {
                inDegree[v]--;
                if(inDegree[v]==0) {
                    q.push(v);
                }
            }
            
        }
        
        return (res.size()==n)? res : vector<int>{};
        
        
    }
};