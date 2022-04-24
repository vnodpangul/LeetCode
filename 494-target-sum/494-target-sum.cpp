// nums = [1,1,1,1,1], target = 3
// rc=0 , currentSum=4-1, rc
class Solution {
public:
    void helper(vector<int> &nums, int idx, int currentSum, int target, int &rc, vector<int> &rightSum)
    {
        if(idx == nums.size()) {
           if (currentSum == target) 
               rc++;
            return;
        }
        if(rightSum[idx]<target-currentSum) return;
        
        int tmpsum = currentSum +nums[idx];
        helper(nums, idx+1, tmpsum, target, rc, rightSum);
        tmpsum = currentSum - nums[idx];
        helper(nums, idx+1, tmpsum, target, rc, rightSum);
        
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int rc = 0;
        if(nums.size() == 0) return rc;
        
        int currentSum = 0;
        int n = nums.size();
        vector<int> rightSum(n, 0);
        rightSum[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            rightSum[i] = nums[i] + rightSum[i+1];
        }
        
        helper(nums, 0, currentSum, target, rc, rightSum);
        return rc;
    }
};