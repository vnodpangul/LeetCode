class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int start=0, end=0;
        int count = 0, res = 0;
        while(end < nums.size()) {
            if(nums[end] == 0) {
                count++;
            }
            end++;
            
            if(count>1) {
                res = max(res, end-start-1);
                
            }
            
            while(count>1) {
                
                if(nums[start] ==0) count--;
                start++;
            }
        }
        
 
        res = max(res, end-start);
        
        return res;
        
    }
};
