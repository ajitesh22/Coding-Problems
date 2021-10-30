class Solution {
public:
    int numDistinct(string s, string t) {
        
        long long int n=t.length(),m=s.length();
        long long int dp[n+1][m+1];
        memset(dp,0,sizeof dp);
        for(int j=0;j<=m;j++)
            dp[0][j]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t[i-1]==s[j-1])
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }  
        return dp[n][m]; 
  }
}


/*

space optimised to 1D Array
        int n = s.length();
        int m = t.length();  
        vector<long long int> dp(m+1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 1; j--) {
        if(s[i-1] == t[j-1])
            dp[j] += dp[j-1];
        }
    }
    return dp[m];


*/
