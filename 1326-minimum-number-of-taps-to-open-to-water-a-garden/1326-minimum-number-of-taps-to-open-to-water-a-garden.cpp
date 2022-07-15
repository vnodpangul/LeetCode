class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        int count = 0;
        int minRange = 0, maxRange = 0;
        while(maxRange<n)
        {
            
            for(int i=0; i<ranges.size(); i++)
            {
                if(i-ranges[i] <= minRange && i+ranges[i] > maxRange)
                {
                    maxRange = i+ranges[i];
                }
            }
            if(minRange==maxRange) return -1;
            count++;
            minRange = maxRange;
        }
        return count;
        
    }
};

// 0 1 2 3 4 5 ... n