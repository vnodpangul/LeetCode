class Solution {
public:
    
    int getNextId(int idx) {
        int low = idx+1, high = data.size()-1;
        int rc = high+1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(data[mid][0] < data[idx][1]) {
                low = mid+1;
            }else {
                rc = mid;
                high = mid-1;
            }
        }
        return rc;
    }
    
    int getMaxProfit(vector<vector<int>> &data, int start, int end) 
    {
        if(start>end) return 0;
        if(dp.find(start) != dp.end()) return dp[start];
        
        int nextId = getNextId(start);
 
        int InclProfit = data[start][2] + getMaxProfit(data, nextId, end);
        int ExclProfit = getMaxProfit(data, start+1, end);
        
        dp[start] = max(InclProfit, ExclProfit);
        return dp[start];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();    
        data.resize(n, vector<int>(3,0));
        for(int i=0; i<n; i++) {
            data[i][0] = startTime[i];
            data[i][1] = endTime[i];
            data[i][2] = profit[i];
        }
        
        struct {
            bool operator()(const vector<int> &a, const vector<int> &b) {
                return a[0]<b[0];
            }
        }compare;
        sort(data.begin(), data.end(), compare);
        
        return getMaxProfit(data, 0, n-1);
    }
private:
    vector<vector<int>> data;
    map<int, int> dp;
};