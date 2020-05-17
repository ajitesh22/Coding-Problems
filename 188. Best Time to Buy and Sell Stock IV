class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
       ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=prices.size();
        if(k>n)
            k=n/2;
        int dp[2][n+1];
        for(int i=0; i<2; i++)
            dp[i][0]=0;
        for(int j=0; j<=n; j++)
            dp[0][j]=0;
        for(int i=1; i<=k; i++){
            int maxDiff=INT_MIN;
            for(int j=1; j<=n ; j++){
                /*int maxValue=INT_MIN;
                for(int x=1; x<j; x++)
                    maxValue=max(maxValue, dp[(i-1)%2][x-1] + prices[j-1] - prices[x-1]);
                */
                maxDiff=max(maxDiff,dp[(i-1)%2][j-1]-prices[j-1]);
                dp[i%2][j] = max(dp[i%2][j-1] , maxDiff+prices[j-1]);
            }   
        }
        return dp[k%2][n];    
    }
};
