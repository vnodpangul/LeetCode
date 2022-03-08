class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int prevBestIdx = 0;
        int res = values[0];
        for(int j=1; j<values.size(); j++)
        {
            res = max(res, values[prevBestIdx]+prevBestIdx+values[j]-j);
            if(values[prevBestIdx]+prevBestIdx < values[j]+j)
                prevBestIdx = j;
            
        }
        return res;
        
    }
};