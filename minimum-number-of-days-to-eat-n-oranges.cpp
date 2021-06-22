//https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges
class Solution {
public:
    
unordered_map<int,int>dp;
int solve(int n){
        
        if(n==1)
            return 1;
        if(n==2)
            return 2;
    
        if(dp.count(n))
            return dp[n]; 
        
        int ans  = INT_MAX;

        if(n%3==0)
            ans = min(ans , 1 + solve(n - 2*(n/3)));
        if(n%2==0)
            ans = min(ans , 1 + solve(n - (n/2)));
               
        if((n-1)%2==0 || (n-1)%3==0)
            ans = min(ans , 1 + solve(n - 1));
        
        if((n-2)%3==0)
            ans = min(ans , 2 + solve(n-2));
        
        return dp[n] = ans ;     
}
    
    
int minDays(int n) {
        int count = 0;
        dp.clear();
        return solve(n);
    }
};
