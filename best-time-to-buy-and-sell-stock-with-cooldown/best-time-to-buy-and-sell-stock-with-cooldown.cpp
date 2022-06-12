class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> noStocks(n,0), inHand(n,0), Sell(n,0);
        
        for(int i=0; i<n; i++) {
            if(i==0) {
                inHand[i] = inHand[i]-prices[i];
                continue;
            }
            noStocks[i] = max(noStocks[i-1], Sell[i-1]);
            inHand[i] = max(inHand[i-1], noStocks[i-1]-prices[i]);
            Sell[i] = (inHand[i-1]+prices[i]);
                
        }
        
        int res = INT_MIN;
        res = max(noStocks[n-1], max(inHand[n-1], Sell[n-1]));
        return res;
    }
};