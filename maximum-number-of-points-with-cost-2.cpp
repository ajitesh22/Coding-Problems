//https://leetcode.com/problems/maximum-number-of-points-with-cost-2.cpp/
#define ll long long int
#define max(a,b)  ((a>=b)? a : b)
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        
        int n = points.size() , m = points[0].size();
        ll ans = 0;
        ll dp[m+1];
        for(int i=0;i<m;i++)
            dp[i] = points[0][i];
        vector<ll> prefixMax(m+1 , 0);
        vector<ll> suffixMax(m+1 , 0);
            
        for(int i=1;i<n;i++){
            

            prefixMax[0] = dp[0];
            for(int j=1;j<m;j++){
                prefixMax[j] = max(dp[j], prefixMax[j-1] - 1);
            }
        
            suffixMax[m-1] = dp[m-1];
            for(int j=m-2;j>=0;j--){
                suffixMax[j] = max(dp[j] , suffixMax[j+1] - 1);
            } 
            
            for(int j=0;j<m;j++){
                dp[j] = points[i][j] + max(prefixMax[j] , suffixMax[j]);
            }  
        }
        for(int i=0;i<m;i++)
            ans = max(ans , dp[i]);
        return ans;
  
    }
};
