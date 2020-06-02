/*

Given a string A, partition A such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of A.


*/


int Solution::minCut(string A) {
   
   int n=A.size();
   int isPalin[n+1][n+1];
   memset(isPalin,0,sizeof(isPalin));
   
   for(int i=0;i<n;i++)
        isPalin[i][i] = 1;
   
   for(int s=1;s<n;s++){
       for(int i=0;i<n-s;i++){
           int j=i+s;
           if(j-i==1){
               isPalin[i][j]= (A[i]==A[j])?1:0;
           }
           else{
               if(A[i]==A[j])
                    isPalin[i][j]=isPalin[i+1][j-1];  
           }
       }
   }
   
   int dp[n+1][n+1];
   memset(dp,0,sizeof(dp));
   
   for(int i=0;i<n;i++)
        dp[i][i] = 0;
   
   for(int s=1;s<n;s++){
       for(int i=0;i<n-s;i++){
           int j=i+s;
            if(j-i==1){
                dp[i][j] = (A[i]==A[j])?0:1;
            }
            else if(isPalin[i][j])
                dp[i][j] = 0;
            else{
                int cut = INT_MAX;
                for(int k=i;k<j;k++){
                    cut = min(cut, dp[i][k] + dp[k+1][j] + 1);
                }
                dp[i][j] = cut;
            }
       }
   }
   return dp[0][n-1];
}
