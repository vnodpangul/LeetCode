class Solution {
private:
    unordered_map<int, int> parents;
    int count = 0;
    unordered_map<int, vector<int>> adjList;
public:
    
    void MakeSet(int n)
    {
        for(int i=0; i<n; i++)
            parents[i] = i;
        count = n;
    }
    
    void buildGraph(int n, vector<vector<int>>& edges)
    {
        for(int i=0; i<edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
    }
    
    int find(int a)
    {
        if(parents[a] != a) {
            parents[a] = find(parents[a]);
        }
        return parents[a];
    }
    
    void makeUnion(int a, int b)
    {
        int p1 = find(a);
        int p2 = find(b);
        if(p1!=p2) {
            parents[p2] = p1;
            count--;
        }
    }
    
    int getCount() { return count;}
    
    bool validTree(int n, vector<vector<int>>& edges) {
        
        MakeSet(n);
        
        buildGraph(n, edges);
        for(int i=0; i<n; i++) {
            for(auto e : adjList[i]) {
                int p1 = find(i);
                int p2 = find(e);
                if(p1 == p2) {
                    return false;
                }else {
                    makeUnion(i, e);
                }

            }
        }
        
        return getCount()==1;
    }
};