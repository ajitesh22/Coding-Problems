//https://leetcode.com/problems/longest-repeating-character-replacement/
class Solution {
public:
    int characterReplacement(string s, int k) {
        
        
        int n = s.size() , maxLen = 0 ;
        
        for(int i=0;i<26;i++){
            int  l = 0 ,r = -1 , cnt = 0;
            while(r < n - 1){
                
                r++;
                int c = s[r] - 'A';
                if(c!=i)
                    cnt++;
                
                while(cnt > k){
                    if(s[l] - 'A' != i)
                        cnt--;
                    l++;
                }
                    
                maxLen = max(maxLen , r - l + 1);
                
            }
        }
        
        return maxLen;
        
        
    }
};
