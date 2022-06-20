class Solution {
    
    struct Node {
        int vertex, weight;
        Node(int v, int w) : vertex(v), weight(w) {}
    };
    vector<vector<Node>> adjList;
    struct comp {
        bool operator()(const Node &lhs, const Node &rhs) {
            return lhs.weight > rhs.weight;
        }
    };
    priority_queue<Node, vector<Node>, comp> pq;
public:
    void buildGraph(int n, vector<vector<int>>& times)
    {
        adjList.resize(n);
        for(auto t : times)
        {
            adjList[t[0]-1].push_back(Node(t[1]-1, t[2]));
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        buildGraph(n, times);
        
        vector<int> prev(n, -1);
        vector<bool> visited(n, false);
        vector<int> dist(n, INT_MAX);
        
        dist[k-1] = 0;
        visited[k-1] = true;
        pq.push(Node(k-1, 0));
        
        while(!pq.empty()) {
            auto node = pq.top(); pq.pop();
            int u = node.vertex;
            for(auto i : adjList[u]) {
                int v = i.vertex;
                int w = i.weight;
                
                if(!visited[v] && dist[v]>(dist[u]+ w)) {
                    dist[v] = dist[u] + w;
                    pq.push(Node(v, dist[v]));
                    prev[v] = u;
                    // visited[v] = true;
                }
            }
            visited[u] = true;
        }
        
        int minCost = INT_MIN;
        for(int i=0; i<n; i++) {
            // cout<<i<<":"<<dist[i]<<endl;
            if(!visited[i]) return -1;
            minCost = max(minCost, dist[i]);
        }
        
        return minCost;
    }
};