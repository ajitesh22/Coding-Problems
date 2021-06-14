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
       option1 = solve(n - coins[idx] , coins , idx , count);
       option2 = solve(n , coins , idx + 1 , count);
        
        count += (option1 + option2);
        
        return dp[n][idx] = count;    
        
    }
    
    
    int CoinChangeIIBottomUp(int amount , vector<int>& coins){
        
    }
    
    
    
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        memset(dp , -1 , sizeof(dp[0])*(amount+1));
        int count = 0;
        return solve(amount , coins , 0 , count);
    }
};
