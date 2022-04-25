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
        int idx = (random()%total_sum)+1;
        auto new_idx_it = lower_bound(wsums.begin(), wsums.end(), idx);
        return new_idx_it - wsums.begin();
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