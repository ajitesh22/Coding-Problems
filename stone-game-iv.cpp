//https://leetcode.com/problems/stone-game-iv/
class Solution {
public:
    
    int dp[100001] ;
    
    int solve(int n){
        
        if(n<=0)
            return 0;
        
        if(dp[n]!=-1)
            return dp[n];
        int ans = 0;
        for(int i=1;i*i<=n;i++){
            ans |= !solve(n-i*i);
        }
        
        return dp[n] = ans ;   
    }
    
    bool winnerSquareGame(int n) {
        memset(dp , -1 , sizeof dp); 
        return solve(n);
    }
};
