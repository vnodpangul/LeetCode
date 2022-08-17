class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> minQ;
        
        int count = 1;
        minQ.push(intervals[0][1]);
        for(int i=1; i<intervals.size(); i++)
        {
            if(!minQ.empty() && minQ.top()<= intervals[i][0]) {
                minQ.pop();
                minQ.push(intervals[i][1]);
            }else {
                minQ.push(intervals[i][1]);
                count++;
            }
        }
        return count;
        
    }
};