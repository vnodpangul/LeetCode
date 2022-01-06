#if 0
class Solution {
public:
    int helper(vector<int> &nums, int idx) {
        if(idx>= nums.size())
            return 0;
        if(cache.count(idx))
            return cache[idx];
        int total1= nums[idx] + helper(nums, idx+2);
        int total2 = helper(nums, idx+1);
        return cache[idx] = max(total1, total2);
    }
    
    int rob(vector<int>& nums) {
        return helper(nums, 0);
    }
private:
    map<int, int> cache;
};
#endif

#if 0
//  DP version, O(n) & O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int profit = 0;
        if(n==0) return profit;
        
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        dp[n-1] = nums[n-1];
        for(int i=n-2; i>=0 ; i--) {
            dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
        }
        return dp[0];
    }
};
#endif

#if 1
// Optimized DP version, O(n) & O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int profit = 0;
        if(n==0) return profit;
        
        int nextHomePlusOne = 0;
        int nextHome = nums[n-1];
        int currentMax = nums[n-1];
        for(int i=n-2; i>=0 ; i--) {
            currentMax = max(nums[i]+nextHomePlusOne, nextHome);
            nextHomePlusOne = nextHome;
            nextHome = currentMax;
            
        }
        return currentMax;
    }
};
#endif
