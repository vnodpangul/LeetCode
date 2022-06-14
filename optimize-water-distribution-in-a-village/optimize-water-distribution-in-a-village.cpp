class Solution {
    struct Node {
        int src, dest, weight;
        
        Node(int s, int d, int w) : src(s), dest(d), weight(w) {}
    };
    vector<Node> edges;
    
    struct compDescend {
        bool operator()(const Node &lhs, const Node &rhs) {
            return lhs.weight>rhs.weight;
        }
    };
    
    vector<int> parents;
public:
    void makeset(int n) {
        parents.resize(n);
        for(int i=0; i<n; i++) parents[i] = i;
    }
    
    int find(int x) {
        if(parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    void makeUnion(int a, int b) {
        int p1 = find(a);
        int p2 = find(b);
        
        if(p1!=p2) {
            parents[p2] = p1;
        }
    }
    

    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        
        for(int i=0; i<pipes.size(); i++) {
            edges.push_back(Node(pipes[i][0], pipes[i][1], pipes[i][2]));
        }
        
        for(int i=0; i<wells.size(); i++)
            edges.push_back(Node(0, i+1, wells[i]));
        
        sort(edges.begin(), edges.end(), compDescend());
        makeset(n+1);
        
        int res = 0; int count = 0;
        while(count != n) {
            auto n = edges.back(); edges.pop_back();
            
            if(find(n.src) != find(n.dest)) {
                makeUnion(n.src, n.dest);
                res += n.weight;
                count++;
            }
        }
        return res;
    }
};