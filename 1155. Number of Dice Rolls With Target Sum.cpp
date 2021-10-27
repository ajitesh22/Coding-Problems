#define MOD 1000000007
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        
      int dp[d+1][target+1];
        
        memset(dp,0,sizeof(dp[0][0])*(d+1)*(target+1));
        dp[0][0]=1;
        for(int i=1;i<=d;i++){
            for(int j=1;j<=target;j++){
                for(int x=1;x<=f;x++){
                     if(j-x>=0)
                        dp[i][j]=(dp[i][j]+dp[i-1][j-x] )%MOD;   
                }
            }
        }
      
        return dp[d][target];   
    }
};


/*


    d-> no of dices
    f-> no of faces
    target-> target sum
    
    dp[i][j] -> sum we get considering only first i dices having j sum
    
    
    
    dp[d][target]->ans
    
    d = 2 f = 6 t = 7
      f 
    d 0  1. 2. 3. 4. 5.  6
    0 1. 0. 0. 0. 0. 0.  0
    
    1 0  1. 
    
    2 0


    dp[1][2] = for (x : 1 to 6) dp[1][2] + = dp[0][2-x];
    
    O(d*target*f)= 30 * 1000 * 30 = 9*10^5

*/
