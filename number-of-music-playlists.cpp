//https://leetcode.com/problems/number-of-music-playlists/
#define mod 1000000000 + 7
#define ll long long int
class Solution {
public:
    
    //dp[playlist][song] 

    
    
    int numMusicPlaylists(int N, int L, int K) {
        
        ll dp[L+1][N+1] ;
        for(int i=0;i<=L;i++){
            for(int j=0;j<=N;j++){
                dp[i][j] = 0;
            }
        }
        
        dp[0][0] = 1;
        for(int i=1;i<=L;i++){
            for(int j=1;j<=N;j++){
                dp[i][j] +=  dp[i-1][j-1] * (N - j + 1);
                dp[i][j] %= mod;
                dp[i][j] +=  dp[i-1][j] * max(j-K , 0);
                dp[i][j] %= mod;
            }
        }
        
        return dp[L][N];
        
    }
};
