class Solution {
public:
    int maxProfit(vector<int>& prices) {
      long long int n=prices.size(),k=2;
        if(n==0 || n==1)return 0;
        long long int dp[5][n+2];
        for(int i=0;i<5;i++)
        for(int j=0;j<n+1;j++)
            dp[i][j]=0;
        for(int i=1; i<=k; i++){
            long long int maxDiff=INT_MIN;
            for(int j=1; j<=n ; j++){
                maxDiff=max(maxDiff,dp[i-1][j-1]-prices[j-1]);
                dp[i][j] = max(dp[i][j-1] , maxDiff+prices[j-1]);
            }   
        }
        return dp[k][n]; 
}   
};
