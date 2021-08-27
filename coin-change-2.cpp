//https://leetcode.com/problems/coin-change-2/

class Solution {
public:
    
    int dp[5001][3001];
    int CoinChangeIITopDown(int n, vector<int>& coins ,int idx , int count) {
        
        if(n==0)
            return 1;
        if(n<0 || idx==coins.size())
            return 0;
        
        if(dp[n][idx]!=-1)
            return dp[n][idx];
        
       int option1 = 0 , option2 = 0; 
       option1 = CoinChangeIITopDown(n - coins[idx] , coins , idx , count);
       option2 = CoinChangeIITopDown(n , coins , idx + 1 , count);
        
        count += (option1 + option2);
        
        return dp[n][idx] = count;    
        
    }
    
    
    int CoinChangeIIBottomUp(int sum , vector<int>& coins){
        
        int n = coins.size();   
        int dp[n+1][sum+1];
        
        for(int i=0;i<n+1;i++)
            for(int j=0;j<sum+1;j++)
                dp[i][j] = 0;
        dp[0][0] = 1;
        
        for(int i=1;i<=n;i++){ 
            for(int j=0;j<=sum;j++){
               
                dp[i][j] = dp[i-1][j] ;
                if(j - coins[i-1] >=0)
                    dp[i][j] += dp[i][j - coins[i-1]];
                
            }
        }
        
        return dp[n][sum];
    }
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
       // memset(dp , -1 , sizeof(dp[0])*(amount+1));
       // int count = 0;
       // return solve(amount , coins , 0 , count);
        return CoinChangeIIBottomUp(amount , coins);
    }
};
