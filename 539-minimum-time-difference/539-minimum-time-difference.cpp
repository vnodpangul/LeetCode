#define DAY_MINS 1440
class Solution {
    
public:
    #if 1
    int findMinDifference(vector<string>& T) {
        sort(T.begin(), T.end());
        int minDiff = INT_MAX;
        
        for(int i=0; i<T.size(); i++) {
            int j = (i==0) ? T.size()-1 : i-1;
            int diff = getDiff(T[i], T[j]);
            int absDiff = min(diff, DAY_MINS-diff);
            minDiff = min(minDiff, absDiff);
        }
        return minDiff;
    }
    #endif
    
    int getDiff(string t1, string t2)
    {
        int h1 = stoi(t1.substr(0,2));
        int m1 = stoi(t1.substr(3,2));
        int h2 = stoi(t2.substr(0,2));
        int m2 = stoi(t2.substr(3,2));
        
        return abs((h2-h1)*60 + (m2-m1)); 
    }
    
};