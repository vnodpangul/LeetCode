class Solution {
    map<string, vector<pair<string, double>>> adjList;
public:
    
    double DFS(string src, string dest, double w, set<string> &visited)
    {
        if(adjList.find(src)==adjList.end()  || adjList.find(dest)==adjList.end()) return -1.0;
        if(src == dest) return 1.0;
        
        visited.insert(src);
        for(auto v : adjList[src]) {
            if(visited.count(v.first)<=0) {
                double res = DFS(v.first, dest, v.second, visited);
                if(res != -1.0) {
                    return v.second * res;
                }
            }
                
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int i=0;
        for(auto E : equations) {
            adjList[E[0]].push_back(make_pair(E[1], values[i]));
            adjList[E[1]].push_back(make_pair(E[0], 1/values[i]));
            i++;
        }
        
        int n = queries.size();
        vector<double> res;
        
        for(auto Q : queries) {
            set<string> visited;
            double rc;
            rc = DFS(Q[0], Q[1], 1.0, visited);
            res.push_back(rc);
        }
        return res;
    }
};

