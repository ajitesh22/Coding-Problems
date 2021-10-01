//https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:
    int dp[1001][1001];
    int solve(string &text1, string &text2 , int idx1 , int idx2){
        
        if(idx1==text1.size() || idx2==text2.size())
            return 0;
        
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        
        int maxLength = 0;
        
        if(text1[idx1] == text2[idx2])
            maxLength = 1 + solve(text1 , text2 , idx1+1 ,idx2+1);
        else
            maxLength = max(solve(text1 , text2 , idx1+1 ,idx2), 
                            solve(text1 , text2 , idx1 ,idx2+1));
        return dp[idx1][idx2] = maxLength;
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        memset(dp , -1 ,sizeof(dp));
        return solve(text1 ,text2,0,0);
    }
};
