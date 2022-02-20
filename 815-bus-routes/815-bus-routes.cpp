class Solution {
public:
    void buildGraph(vector<int> &route, int n)
    {
        for(int i=0; i<route.size(); i++) {
            adjList[route[i]].push_back(n);
        }
    }
    
    int BFS(int start, int target, vector<vector<int>>& routes)
    {
        queue<pair<int, int>> q;
        q.push({start, 0});
        while(!q.empty())
        {
            auto [stop, busCount] = q.front(); q.pop();
            
            if(stop == target)
                return busCount;
            visited.insert(stop);
            for(auto i : adjList[stop]) {
                for(auto j : routes[i]) {
                    if(visited.count(j))
                        continue;
                    else{
                        visited.insert(j);
                        q.push({j, busCount+1});
                    }
                }
                routes[i].clear();
            }
        }
        return -1;
        
    }
    
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
       
        for(int i=0; i<routes.size(); i++) {
            buildGraph(routes[i], i);
        }
        
        return BFS(source, target, routes);
    }
private:
    unordered_map<int, vector<int>> adjList;
    set<int> visited;
    int rc = INT_MAX;
        
};

/*
[0] --> 1,2,7
[1] --> 3,6,7

    
[1]--> 2
[2]--> 7
[7]--> 1
[3]--> 6
[6]--> 7  | IndegreeOF 7 = 2
[7]--> 6
    
    [1]--> 2
    [2] -->7
[[7,12],[4,5,15],[6],[15,19],[9,12,13]]

[7] --> <12,0>
[12] --> <7,0>
*/