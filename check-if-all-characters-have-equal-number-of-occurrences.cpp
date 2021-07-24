https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        
        int f[26] = {0};
        int n = s.size();
        for(char c : s)
            f[c - 'a']++;
        
        int c = 0;
        for(int i=0;i<26;i++){
            if(f[i]>0){
                if(c==0)
                    c=f[i];
                else{
                    if(f[i]!=c)
                        return false;
                }
            }
                
        }
        return true;
    }
};
