class Solution {
private:
    vector<int> parents;
    int count = 0;
public:
    void makeset(int n) {
        parents.resize(n, -1);
        for(int i=0; i<n; i++)
            parents[i] = i;
        count = n;
    }
    int getCount() { return count; }
    int find(int x) {
        if(parents[x]!=x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    void makeUnion(int a, int b)
    {
        int p1 = find(a);
        int p2 = find(b);
        if(p1 != p2) {
            parents[p2] = p1;
            count--;
        }
    }

          
    static bool sortCol(const vector<int> &lhs, const vector<int> &rhs) {
        return lhs[0]<rhs[0];
    } 
    int earliestAcq(vector<vector<int>>& logs, int n) {
        
        makeset(n);
      
        sort(logs.begin(), logs.end(), sortCol);
        for(int i=0; i<logs.size(); i++) {
            int p1 = find(logs[i][1]);
            int p2 = find(logs[i][2]);
            
            if(p1!=p2) {
                makeUnion(p1, p2);
                if(getCount()==1) {
                    return logs[i][0];
                }
            }
            
        }
        
        return -1;
    }
};