https://www.lintcode.com/problem/1884/solution/32289
class Solution {
public:
    /**
     * @param arr: the array of bottles
     * @return: the minimum number of times you can take all the bottles
     */

    int solve(vector<int> &arr , int l ,int r , vector<int>& used){

    }

    int takeAwayTheBottle(vector<int> &arr) {
        // Write your code here.
        int n = arr.size();
        int dp[n][n] ;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = n;
            }
        }
        
        for(int i=0;i<n;i++)
            dp[i][i] = 1;
        
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1])
                dp[i][i+1] = 1;
            else
                dp[i][i+1] = 2;
        }

        for(int s = 2; s < n ; s++){
            for( int i = 0 ; i < n - s ; i++){
                int  j = i + s;
                if(arr[i]==arr[j])
                    dp[i][j] =  dp[i+1][j-1];
                else
                    dp[i][j] = 1 + dp[i+1][j-1];

                for(int k=i;k<j;k++)
                    dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k+1][j]);
                
            }
        }

        return dp[0][n-1];
    }
};
