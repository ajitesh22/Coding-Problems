//https://leetcode.com/problems/coin-change/
class Solution {
public:
    
    int dp[13][10001];
    
    int CoinChangeTopDown(vector<int>& coins , int amount , int idx){
        
        if(amount == 0)
            return 0;
        if(amount < 0 || idx==coins.size())
            return 10001;
        
        
        if(dp[idx][amount]!=-1)
            return dp[idx][amount];
    
        
        return dp[idx][amount] = min(1 + CoinChangeTopDown(coins , amount - coins[idx] , idx),
                                        CoinChangeTopDown(coins , amount , idx + 1));      
    }
    
    
    int coinChangeBottomUp(vector<int>& coins, int amount) {
        
        if(amount==0)
            return 0;
        int n=coins.size();
        vector<int>dp(amount+1,INT_MAX);
        for(int i=0;i<n;i++)
            if(coins[i]<=amount)
                dp[coins[i]]=1;
        
        for(int i=0;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(i-coins[j]>0 && dp[i-coins[j]]!=INT_MAX){
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        
        if(dp[amount]!=INT_MAX)
            return dp[amount];
        return -1;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        memset(dp, -1 , sizeof(dp[0])*n);
        int ans = CoinChangeTopDown(coins , amount , 0 );
        return (ans>=10001) ? -1 : ans ; 
        
        
    }
};
