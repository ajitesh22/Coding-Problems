//https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
#define mod 1000000007
class Solution {
public:
    int countOrders(int n) {
        
        
        long long int dp[501] = {0};
        dp[1] = 1 ; dp[2] = 6 ;
        
        for(int i=3;i<=n;i++){
            int spaces = (i-1)*2 + 1;
            dp[i] = dp[i-1]*((spaces)*(spaces+1)/2)%mod;
         }
        
        return dp[n];
        
    }
};
