//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        
        int n = prices.size();
        
        int oldBoughtStateProfit = -prices[0] ;
        int oldSellStateProfit = 0;
        
        
        for(int i = 1 ; i<n ; i++){
            int newBoughtStateProfit = 0 ;
            int newSellStateProfit   = 0;
            
            if(oldSellStateProfit - prices[i] > oldBoughtStateProfit)
                newBoughtStateProfit = oldSellStateProfit - prices[i] ;
            else
                newBoughtStateProfit = oldBoughtStateProfit;

            if(oldBoughtStateProfit + prices[i] - fee > oldSellStateProfit)
                newSellStateProfit = oldBoughtStateProfit + prices[i] - fee ;
            else
                newSellStateProfit = oldSellStateProfit;
            
            
            oldBoughtStateProfit = newBoughtStateProfit;
            oldSellStateProfit = newSellStateProfit;
            
        }
        
        return max(oldBoughtStateProfit , oldSellStateProfit);
        
        
    }
};
