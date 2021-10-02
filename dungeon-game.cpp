//https://leetcode.com/problems/dungeon-game/
class Solution {
public:
    
    
    int isPossibleToReachEnd(vector<vector<int>>& dungeon , int startHealth){
        
        int n = dungeon.size() , m = dungeon[0].size();
        vector<vector<int>> dp(n , vector<int>(m,0));
        
        dp[0][0] = ((startHealth + dungeon[0][0])>0 ) ? startHealth + dungeon[0][0] : -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)
                    continue;
                dp[i][j] = -1;
                if(i==0 && dp[i][j-1]>0)
                    dp[i][j] = dungeon[i][j] + dp[i][j-1];
                if(j==0 && dp[i-1][j]>0)
                    dp[i][j] = dungeon[i][j] + dp[i-1][j];
                if(i!=0 && j!=0){
                    if(max(dp[i-1][j] , dp[i][j-1])>0)
                        dp[i][j] = dungeon[i][j] + max(dp[i-1][j] , dp[i][j-1]);
                } 
            }
        }
        return dp[n-1][m-1];
    }
    
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        //binary search range [-1000 , 1000]
        // N*M*log(search space size)
        
        int l = 1 , r = 10000000;
        
        while(l<r){
            
            int mid = l + (r -l)/2;
            if(isPossibleToReachEnd(dungeon , mid)>0)
                r=mid;
            else
                l=mid+1;   
        }
        
        
        return l;
        
    }
};
