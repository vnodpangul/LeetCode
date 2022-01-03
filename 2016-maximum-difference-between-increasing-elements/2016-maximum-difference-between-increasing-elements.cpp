class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1;
        int minNum = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]<minNum) {
                minNum = nums[i];
            }
            if(nums[i]>minNum)
                maxDiff = max(maxDiff, nums[i]-minNum);
        }
    
        return maxDiff;
    }
};