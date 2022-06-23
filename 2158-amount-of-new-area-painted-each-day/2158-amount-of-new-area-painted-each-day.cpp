class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        int minStart = INT_MAX, maxEnd = 0;
        for(auto p : paint) {
            minStart = min(minStart, p[0]);
            maxEnd = max(maxEnd, p[1]);
        }
        
        set<int> area;
        for(int i=minStart; i<=maxEnd; i++)
            area.insert(i);
        
        vector<int> res; res.reserve(paint.size());
        for(auto p : paint) {
            int s = p[0];
            int count = 0;
            auto it = area.lower_bound(s);
            while(it!=area.end() && *it<p[1]) {
                it = area.erase(it);
                count++;
            }
            res.push_back(count);
            
        }
        return res;
    }
};