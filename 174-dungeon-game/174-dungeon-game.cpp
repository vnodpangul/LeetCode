// https://leetcode.com/problems/dungeon-game/discuss/745340/post-Dedicated-to-beginners-of-DP-or-have-no-clue-how-to-start 

#if 0
// Approach 1 : TLE
class Solution {
public:
    int helper(vector<vector<int>>& dungeon, int m, int n, int i, int j)
    {
        if(i==m || j==n) {
            return INT_MAX;
        }
        if(i==m-1 && j==n-1) {
            return dungeon[i][j]<=0 ? -dungeon[i][j]+1 : 1;
        }
        
        int rightCost = helper(dungeon, m, n, i, j+1);
        int leftCost = helper(dungeon, m, n, i+1, j);
        
        int minCost = min(leftCost, rightCost) - dungeon[i][j];
        return (minCost <= 0) ? 1 : minCost;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int m = dungeon.size();
        int n = dungeon[0].size();
        return helper(dungeon, m, n, 0, 0);
        
    }
}; 
#endif

#if 0
// Aproach 2: Recursion with memomization

class Solution {
public:
    int helper(vector<vector<int>>& dungeon, int m, int n, int i, int j, 
              vector<vector<int>> &dp)
    {
        if(i==m || j==n) {
            return INT_MAX;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(i==m-1 && j==n-1) {
            return dungeon[i][j]<=0 ? -dungeon[i][j]+1 : 1;
        }
        
        int rightCost = helper(dungeon, m, n, i, j+1, dp);
        int leftCost = helper(dungeon, m, n, i+1, j, dp);
        
        int minCost = min(leftCost, rightCost) - dungeon[i][j];
        dp[i][j] = (minCost <= 0) ? 1 : minCost;
        return dp[i][j];
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(dungeon, m, n, 0, 0, dp);
        
    }
}; 
#endif


#if 1
// Aproach 3: DP

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[m-1][n] = 1;
        dp[m][n-1] = 1;
        
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                int healthCount = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = healthCount <= 0 ? 1 : healthCount;
            }
        }
        
        return dp[0][0];
        
    }
}; 
#endif

