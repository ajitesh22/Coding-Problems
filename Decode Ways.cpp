//Decode Ways
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int dp[n];
        dp[0] = 1;
        if(s[0]=='0')
            return 0;
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                dp[i] = 0;
                if(i-2>=0 && (int)(s.substr(i-1,2) <=26)){
                    dp[i] = dp[i-2];
                }
                if(i-2<0)
                    dp[i] = 1;
                
            }
            else {
                dp[i] = dp[i-1];
                if(int(s.substr(i-1 ,2)<=26))
                    dp[i] = dp[i-1];
            }

        }
        
        return dp[n-1];
        
    }
};

/*
 
          2   2       6
dp[i]     1   1 +1    3

         1   1     1     0      6 
         1   2     2+1   2      2 



*/
