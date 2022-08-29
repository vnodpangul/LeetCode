class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
     for(int i=0; i<nums.size(); i++)
     {
         if(nums[i]<0) nums[i] = 0;
     }
        
    
    int size = nums.size();
    for(int i=0; i<nums.size(); i++)
    {
        int val = abs(nums[i]);
        if(val>0 && val<=size)
        {
            int idx = val-1;
            if(nums[idx]>0) nums[idx] *= -1;
            
            else if(nums[idx]==0) nums[idx] = (1+size)*-1;
        }
        
    }
    
    for(int i=1; i<=size; i++)
    {
        if(nums[i-1]>=0) return i;
    }
    
    return size+1;
        
    }
};