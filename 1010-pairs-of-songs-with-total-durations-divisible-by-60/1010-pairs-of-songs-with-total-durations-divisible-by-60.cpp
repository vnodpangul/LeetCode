class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        vector<int> remainders(60,0);
        int res = 0;
        for(auto t: time) {
            
            if(t%60==0) {
                res += remainders[0];
            }else {
                res += remainders[60-(t%60)];
            }
            remainders[t%60]++;
        }
        return res;
    }
};