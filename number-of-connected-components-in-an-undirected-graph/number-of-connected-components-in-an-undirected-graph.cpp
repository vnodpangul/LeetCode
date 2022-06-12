class Solution {
    vector<int> parents;
    int count = 0;
public:
    void makeset(int n) {
        parents.resize(n, -1);
        for(int i=0; i<n; i++)
            parents[i] = i;
        count = n ;
    }
    int find(int i) {
        if(parents[i] != i) {
            parents[i] = find(parents[i]);
        }
        return parents[i];
    }
    void makeUnion(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa!=pb) {
            parents[pb] = pa; 
            count--;
        }
    }
    int getCount() { return count; }
    int countComponents(int n, vector<vector<int>>& edges) {
        makeset(n);
        for(int i=0; i<edges.size(); i++) {
            int x = find(edges[i][0]);
            int y = find(edges[i][1]);
            if(x!=y)
                makeUnion(x,y);
        }
        
        return getCount();
    }
};