class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Profit = 0;
        if(prices.size()<=1) return Profit;
        
        int minBuy = prices[0], maxSell = prices[0];
 
        for(int i=1; i<prices.size(); i++) {
            if(prices[i]<prices[i-1]) {
                Profit += prices[i-1] - minBuy;
                minBuy = prices[i];

            }else {
                maxSell = prices[i];
                if(i==prices.size()-1)
                     Profit += maxSell-minBuy;
            }
        }

        return Profit;
    }
};