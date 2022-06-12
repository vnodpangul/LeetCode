class Solution {
public:
    
    void makeSet(int n) {
        for(int i=0; i<n; i++)
            parents[i] = i;
        count = n;
    }
    
    int find(int x) {
        if(parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x]; 
    }
    
    void makeUnion(int x, int y) {
        int xp = find(x);
        int yp = find(y);
        
        if(xp != yp) {
            parents[yp] = xp;
            count--;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        makeSet(n);
        
        for(int i=0; i<isConnected.size(); i++) {
            for(int j=0; j<isConnected[0].size(); j++) {
                if(isConnected[i][j] == 1) {
                    makeUnion(i, j);
                }
            }
        }
        
        // set<int> visited;
        // for(auto &elm : parents)
        //     visited.insert(elm.second);
        // return visited.size();
        
        return getCount();
        
        
    }
    
    int getCount() {
        return count;
    }
    
private:
    unordered_map<int, int> parents;
    int count = 0;
};
