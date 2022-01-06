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