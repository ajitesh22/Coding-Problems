//https://leetcode.com/problems/palindromic-substrings/
class Solution {
public:
    

    
int countSubstrings(string s) {
        
    
        int n=s.size(),count=0;
        if(n==0)return 0;
        int dp[n+1][n+1];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=0;
        
        for(int i=0;i<n;i++){
            dp[i][i]=1;count++;
        }
        for(int i=1;i<n;i++){
            dp[i-1][i] = (s[i-1]==s[i])?1:0;
            count+=dp[i-1][i];
        } 
        for(int k=2;k<n;k++){
            for(int i=0;i<n-k;i++){
                int j=k+i;
                dp[i][j] = ((s[i]==s[j]) && dp[i+1][j-1])?1:0;
                count +=dp[i][j];
            }
        }
        
        
        return count;
        
        
    }
};



/*


         a    a   a

         0.  1.  2.  3.  4
         a   b   a   b   a
         
         s[0:4] is palindrome ? -> if s[0] == s[4]  &&  s[1:3] is palindrome
         
         s[1:3] is palindrome?   -> if s[1] == s[3]  &&   s[2] is palindrome
         
         s[2] is palindrome? 1 
         

*/
