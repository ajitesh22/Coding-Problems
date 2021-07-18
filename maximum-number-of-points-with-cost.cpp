//https://leetcode.com/problems/maximum-number-of-points-with-cost/
#define ll long long int
#define max(a,b) (a>=b)? a : b
class Solution {
public:

    int solve(vector<vector<int>>& points , vector<vector<ll>> &dp , int row , int col ){
        
        if(row == points.size())
            return 0;
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        ll score = INT_MIN;
        for(int j=0;j<points[0].size();j++){
            if(dp[row][j]!=-1)
                score = max(score , dp[row][j] - abs(col - j));
            else
                score = max(score , points[row][j] + solve(points , dp , row + 1 , j) - abs(col - j));
        }
        return dp[row][col] = score;
    }
    
    long long maxPoints(vector<vector<int>>& points) {
        
        ll n = points.size() , m = points[0].size();
        ll ans = 0 ,currScore = 0 ;
        
        vector<vector<ll>> dp(n+1 , vector<ll>(m+1 ,-1));
        
        for(int i=0;i<m;i++){
            dp[0][i] = points[0][i] +  solve(points , dp , 1 , i);
            ans = max(ans , dp[0][i]);
        }
        return ans;
    }
};
