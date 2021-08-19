class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.size();
        if(!s.size())
            return 0;
        vector<int>dp(n+1);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--){
            dp[i]=0;
            if(s[i]!='0'){
                dp[i] = dp[i+1];
                if(i<n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6')))
                    dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};
