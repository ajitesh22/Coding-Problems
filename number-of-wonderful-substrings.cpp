//https://leetcode.com/problems/number-of-wonderful-substrings/
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        
        long long int dp[1025] = {0};
        dp[0] = 1;
        long long int mask = 0 , cnt = 0;
        for(int i=0;i<word.size();i++){
            mask = mask^(1<<(word[i] - 97));
            cnt += dp[mask];
            for(int j=0;j<10;j++){
                cnt += dp[mask^(1<<(j))];
            } 
            dp[mask] +=1;

        }
        return cnt;   
    }
};
