//https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible
#define mod 1000000007
#define ll long long int
class Solution {
public:
    vector<vector<ll>> dp;
    ll numberOfWays(int n , int k){
        
        if((n==0 && k!=0) || (n!=0 && k==0))
            return 0;
        
        if(n==0 && k==0)
            return 1;
        
        if(dp[n][k]==-1){

            dp[n][k] = (numberOfWays(n-1,k-1)%mod +((n-1)*numberOfWays(n-1,k)%mod)%mod )%mod;
        }
        return dp[n][k]%mod;
    }

    int rearrangeSticks(int n, int k) {
        
        dp = vector<vector<ll>>(n+1,vector<ll>(k+1,-1));
        return numberOfWays(n,k)%mod; 
    }
};
