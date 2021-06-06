//https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
class Solution {
public:
    int minFlips(string s) {
        
        int  n = s.size();
        
        s = s + s;
        string altStr1 ="" , altStr2="";
        
        for(int i=0 ; i < 2*n ;i++){
            altStr1 +=  (i%2)? '1' : '0';
            altStr2 +=  (i%2)? '0' : '1';
        }
        
        int ans = n , windowAns1 = 0 , windowAns2 = 0;
        
        for(int i=0;i<2*n;i++){
            
            if(s[i]!=altStr1[i])windowAns1++;
            if(s[i]!=altStr2[i])windowAns2++;
            
            if(i>=n){
                if(s[i-n]!=altStr1[i-n])windowAns1--;
                if(s[i-n]!=altStr2[i-n])windowAns2--;
            }
            
            if(i>=n-1)
                ans = min(ans , min(windowAns1 , windowAns2));   
        }
        
        return ans;
  
    }
};
