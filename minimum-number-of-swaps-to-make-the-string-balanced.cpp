//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced
class Solution {
public:
    int minSwaps(string s) {
        
        int cnt = 0 , ans = 0;
        for(int i=0;i<s.size();i++){
            cnt += (s[i]=='[')?1:-1;
            if(cnt<0){
                ans++;
                cnt=1;
            }
        }
        return ans;

    }
};
