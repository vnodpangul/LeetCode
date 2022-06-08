class Solution {
public:
    
    int dfs(vector<int>& jd, int i, vector<vector<int>> &dp, int d)
    {
        if(d>jd.size()) return -1;
        if(d==1) {
            int maxJob = -1;
            for(int j=i; j<jd.size(); j++) maxJob = max(maxJob, jd[j]);
            return maxJob;
        }
        if(dp[d][i] != -1)
            return dp[d][i];
        
        int maxJob = INT_MIN;
        int res = INT_MAX;
        for(int j=i; j<jd.size()-d+1; j++) {
            maxJob = max(maxJob, jd[j]);
            res = min(res, maxJob+dfs(jd, j+1, dp, d-1));
        }
        return dp[d][i] = res;
 
    }
    
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        if(n<d) return -1;
        vector<vector<int>> dp(d+1, vector<int>(n, -1));
        
        return dfs(jobDifficulty, 0, dp, d);
        
    }
};