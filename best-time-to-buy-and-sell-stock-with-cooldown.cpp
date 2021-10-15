https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int>dp(n,0);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int prevMax = 0;
                if(j>1)
                    prevMax = dp[j-2];
                dp[i] = max(dp[j] , max(dp[i] , prevMax + prices[i] - prices[j]));
            }
        }
        
        return dp[n-1];
        
    }
};

/*

dp[j-2] + prices[i] - prices[j] =  prices[i] + ( dp[j-2]  - prices[j] )



*/
