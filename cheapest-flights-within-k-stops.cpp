//https://leetcode.com/problems/cheapest-flights-within-k-stops/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
         vector<vector<long> > dp( K+2 , vector<long> (n+1, INT_MAX)); 
        dp[0][src] = 0;
        for(int i=1;i<=K+1;i++){
            dp[i][src] = 0;
            for(auto flight : flights){
                dp[i][flight[1]] = min(dp[i][flight[1]],dp[i-1][flight[0]] + flight[2]);
            }
        }
        return (dp[K+1][dst]==INT_MAX) ? -1 : (int)dp[K+1][dst];     
    }
};
