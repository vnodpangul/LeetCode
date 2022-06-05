class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> minDP(n+1, 0);
        
        // minDP[0] = cost[0];
        // minDP[1] = cost[1];
        
        for(int i=2; i<=n; i++) {
            minDP[i] = min((cost[i-1]+minDP[i-1]), (cost[i-2]+minDP[i-2]) );
        }
        
        return minDP[n];
    }
};