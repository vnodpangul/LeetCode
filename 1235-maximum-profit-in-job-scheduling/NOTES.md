```
/*
https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/1484705/Different-Approaches-oror-Linear-and-Binary-Search-oror-C%2B%2B
​
*/
class Solution {
public:
int getNextIdx(vector<vector<int>>&data, int &idx, int n) {
for(int i=idx+1; i<n; i++) {
if(data[idx][1]<=data[i][0]) return i;
}
return n;
}
int getNextIdxBS(vector<vector<int>>&data, int &idx, int n) {
int low = idx+1;
int high = n-1;
int rc = n;
while(low<=high){
int mid = (low+high)>>1;
if(data[idx][1]<=data[mid][0]) {
rc = mid;
high = mid-1;
}
else low = mid+1;
}
return rc;
}
unordered_map<int, int> dp;
int getMaxProfit(vector<vector<int>>&data, int idx, int n) {
if(idx == n) return 0;
if(dp.find(idx) != dp.end()) return dp[idx];
int nextIdx = getNextIdxBS(data, idx, n);
int incl = data[idx][2] + getMaxProfit(data, nextIdx, n);
int excl = getMaxProfit(data, idx+1, n);
return dp[idx] = max(incl, excl);
}
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
vector<vector<int>> data(startTime.size(), vector<int>(3, 0));
int rc=0;
for(int i=0; i<startTime.size(); i++) {
data[i][0] = startTime[i];
data[i][1] = endTime[i];