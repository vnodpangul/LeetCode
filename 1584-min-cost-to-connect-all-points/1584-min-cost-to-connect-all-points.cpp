class Solution {
    struct Node {
        int src, dest, weight;
        Node(int s, int d, int w) : src(s), dest(d), weight(w) {}
    };
    
    vector<Node> edges;
    struct compDescend {
      bool operator()(const Node &lhs, const Node &rhs) {
          return lhs.weight > rhs.weight;
      }  
    };
    
    vector<int> parents;
public:
    /* Union-find Related */
    void makeset(int n) {
        parents.resize(n, -1);
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
            parents[p2]=p1;
        }
    }
    
    /* Points Related */
    int getManhattenDist(vector<int> x , vector<int> y) {
        return abs(abs(y[0]-x[0]) + abs(y[1]-x[1]));
        
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        for(int i=0; i<points.size(); i++) {
            for(int j=i+1; j<points.size(); j++) {
                
                if(i!=j) {
                    int w = getManhattenDist(points[i], points[j]);
                    edges.push_back(Node(i, j, w));
                }
            }
        }
        sort(edges.begin(), edges.end(), compDescend());
        
        int n = points.size();
        makeset(n);
        
        int count = 0; int res = 0;
        while(count != n-1) {
            auto n = edges.back(); edges.pop_back();
            // cout<<n.src<<" "<<n.dest<<" "<<n.weight<<endl;
            int p1 = find(n.src);
            int p2 = find(n.dest);
            
            if(p1!=p2) {
                makeUnion(n.src, n.dest);
                res += n.weight;
                count++;
            }
            
            
        }
        
        return res;
        
    }
};