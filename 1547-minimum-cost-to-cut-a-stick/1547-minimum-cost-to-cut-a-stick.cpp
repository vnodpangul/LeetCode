class Solution {
    vector<vector<int>> dp;
    int cutsSize = 0;
    vector<int> _cuts;
public:
    
    int helper(int i_idx, int j_idx, int l, int h)
    {
        if(i_idx<0 || j_idx>=cutsSize || i_idx>j_idx)
        {
            return 0;
        }
        
        if(i_idx == j_idx) return h-l;
        if(dp[i_idx][j_idx] != -1) return dp[i_idx][j_idx];
        
        int res = INT_MAX;
        for(int i=i_idx; i<=j_idx; i++)
        {
            res = min(res, (h-l)+helper(i_idx, i-1, l, _cuts[i])
                     + helper(i+1, j_idx, _cuts[i], h));
        }
        return dp[i_idx][j_idx] = res;
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        
        sort(cuts.begin(), cuts.end());
        _cuts = cuts;
        
        
        int l=0, h=n;
        int i_idx = 0, j_idx=cuts.size()-1; cutsSize = j_idx+1;
        dp.resize(cutsSize, vector<int>(cutsSize, -1));
        
        return helper(i_idx, j_idx, l, h);
    }
};