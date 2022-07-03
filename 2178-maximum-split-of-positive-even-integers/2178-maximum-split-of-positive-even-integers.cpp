class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> res;
   
        
        if(finalSum%2!=0) return res;
        
        int i=2;
        long long currentSum = 0;
        while((currentSum+i)<=finalSum){
            res.push_back(i);
            currentSum += i;
            i+=2;
        }
        
        res[res.size()-1] += (finalSum-currentSum);
        
        return res;
    }
};