class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> rc = {-1, -1};
        
        int l=0, h = nums.size()-1;
        while(l<=h) {
            int mid = l + (h-l)/2;
            if(nums[mid]<target)
                l = mid+1;
            else if(nums[mid]>target)
                h = mid-1;
            else if(nums[mid] == target) {
                rc[0] = mid;
                h = mid-1;
            }
        }
        if(rc[0]==-1) return rc;
        
        l = rc[0], h = nums.size()-1;
        while(l<=h) {
            int mid = l + (h-l)/2;
            if(nums[mid]<target)
                l = mid+1;
            else if(nums[mid]>target)
                h = mid-1;
            else if(nums[mid] == target) {
                rc[1] = mid;
                l = mid+1;
            }
        }
        
        return rc;
    }
};