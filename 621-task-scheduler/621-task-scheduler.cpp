class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int, vector<int>> maxHeap;
        queue<pair<int,int>> q; // Count, Time
        vector<int> freq(26, 0);
        
        for(int i=0; i<tasks.size(); i++) {
            freq[tasks[i]-'A']++;
        }
        for(auto elem: freq) {
            if(elem>0) maxHeap.push(elem);
        }
        // cout<<"\n HeapSize: "<<maxHeap.size();
        
        int time = 0;
        while(!maxHeap.empty() || !q.empty()) {
            time++;
            if(!maxHeap.empty()) {
                int count = maxHeap.top(); maxHeap.pop();
                // cout<<"\n PoppedFreq: time"<<count<<" : "<<time;
                count--;
            
                if(count>0) {
                    q.push(make_pair(count, time+n));
                }
            }
           
            if(!q.empty() && q.front().second <= time) {
                // cout<<"\n QFront: "<<q.front().first<<":"<<q.front().second;
                int freq = q.front().first;
                q.pop();
                maxHeap.push(freq);
            }
            
        }
        
        return time;
        
    }
};
