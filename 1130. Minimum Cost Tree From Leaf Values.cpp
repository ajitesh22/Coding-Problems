//https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        int n=arr.size();
        int maxElement[n][n];
        
        for(int i=0;i<n;i++){
            int currMax = arr[i];
            for(int j=i;j<n;j++){
                currMax =max(currMax,arr[j]);
                maxElement[i][j] = currMax;
            }  
        }
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=INT_MAX;
        for(int i=0;i<n;i++){
            dp[i][i] = 0;
        }

       for(int s = 1; s < n ; s++){
        for( int i = 0 ; i < n - s ; i++){
            int  j = i + s;
            for(int k=i;k<j;k++){
                dp[i][j] = min(dp[i][j],maxElement[i][k]*maxElement[k+1][j] + dp[i][k] + dp[k+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
