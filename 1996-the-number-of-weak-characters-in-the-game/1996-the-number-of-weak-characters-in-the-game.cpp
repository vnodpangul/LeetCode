class Solution {
public:
    static bool comp(const vector<int> &lhs, const vector<int> &rhs)
        {
            if(lhs[0]==rhs[0])
            {
                return lhs[1]>rhs[1];
            }
            return lhs[0] < rhs[0];
        }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        sort(properties.begin(), properties.end(), comp);
        int maxDef = INT_MIN;
        int n = properties.size();
        int res = 0;
        for(int i=n-1; i>=0; i--)
        {
            if(properties[i][1] < maxDef)
            {
                res++;
                
            }
            maxDef = max(maxDef, properties[i][1]);
        }
        return res;
    }
};