class Solution {
    map<int, int> locs;
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        for(int i=0; i<trips.size(); i++)
        {
            int cap = trips[i][0];
            int st = trips[i][1];
            int end = trips[i][2];
            
            locs[st] += cap;
            locs[end] -= cap;
        }
        
        for(auto &elem : locs)
        {
            capacity -= elem.second;
            if(capacity<0) return false;
        }
        return true;
        
        
    }
};