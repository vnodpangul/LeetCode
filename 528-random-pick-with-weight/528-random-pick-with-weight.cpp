class Solution {
public:
    Solution(vector<int>& w) {
        wsums.push_back(w[0]);
        total_sum = w[0];
        for(int i=1; i<w.size(); i++) {
            total_sum += w[i];
            wsums.push_back(total_sum);
            
        }
    }
    
    int pickIndex() {
        int idx = (random()%total_sum);
        int l = 0, r = wsums.size()-1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(idx< wsums[mid]) {
                r = mid-1;
            }else {
                l = mid+1;
            }
        }
        return l;
    }
private:
    vector<int> wsums;
    int total_sum = 0;
    
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */