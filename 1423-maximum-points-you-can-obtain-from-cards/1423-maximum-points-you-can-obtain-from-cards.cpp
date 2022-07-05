class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0, maxSum = INT_MIN;
        int l = 0, r = cardPoints.size()-1;
        while(l<k)
        {
            sum += cardPoints[l++];
        }
        maxSum = max(sum, maxSum);
        l--;
        
        while(k>0)
        {
            if(l>=0)
            {
                sum += cardPoints[r] - cardPoints[l];
            }
            maxSum = max(maxSum, sum);
            l--;
            r--;
            k--;
        }
        return maxSum;
    }
};

/*
[0] = 11
[1] = 60
[2] = 160
[3] = 180
[4] = 266
[5] = 296
[6] = 368
    
[0] = 267
[1] = 256
[2] = 207
[3] = 207
[4] = 187
[5] = 101
[6] = 72
*/