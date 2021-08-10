//https://leetcode.com/problems/flip-string-to-monotone-increasing/
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int zeroCnt = 0 , n = s.size();
        for(char c : s)
            zeroCnt += (c=='0')?1:0;
        
        int currZero = 0 , ans = zeroCnt;
        for(int i=0;i<n;i++){
            if(s[i]=='0')
                currZero++;
            ans = min(ans , (i+1 - currZero) + (zeroCnt - currZero));
        }
        return ans;
    }
};
