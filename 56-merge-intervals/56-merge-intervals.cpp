class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        
        
        for(int i=1; i<intervals.size(); i++)
        {
            int n = res.size()-1;
            if(intervals[i][0]<=res[n][1]) {
                   res[n][0] = min(res[n][0], intervals[i][0]);
                   res[n][1] = max(res[n][1], intervals[i][1]);
            }else {
                res.push_back(intervals[i]);
            }
            
            
        }
        return res;
        
        
    }
};