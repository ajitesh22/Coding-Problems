//https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts
class Solution {
public:
    
    int vowelToInteger(char c){
        if(c=='a')
            return 0;
        if(c=='e')
            return 1;
        if(c=='i')
            return 2;
        if(c=='o')
            return 3;
        if(c=='u')
            return 4;
        return 5;
    }
    
    int findTheLongestSubstring(string s) {
        
       int dp[33];
       for(int i=0;i<33;i++)
           dp[i]=s.size();
        dp[0] = -1;
        int mask = 0 , maxLength = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i] =='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                mask = mask^(1<<vowelToInteger(s[i]));
            
            maxLength = max(maxLength , i - dp[mask]);
            dp[mask] =min(dp[mask] , i);
                       
        }
        return maxLength;
        
    }
};
