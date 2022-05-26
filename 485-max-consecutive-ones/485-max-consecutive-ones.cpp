class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int res = INT_MIN;
        int count = 0, mask=1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]&mask) {
                count++;
            }else {
                res = max(res, count);
                count = 0;
                mask = 1;
            }
            
        }
        
        return max(res, count);
        
    }
};