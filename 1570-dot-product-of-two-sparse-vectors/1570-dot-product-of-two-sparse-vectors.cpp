class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                data[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res= 0;
        for(int i=0; i<vec.data.size(); i++) {
            if(vec.data[i]!=0 && data.find(i) != data.end()) {
                res += (vec.data[i] * data[i]);
            }
            
        }
        return res;
    }
    private:
        unordered_map<int, int> data;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);