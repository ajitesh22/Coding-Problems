class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& piles, int i ,int j){
        
        if(i==j) return piles[i];
        if(j-1==i) return max(piles[i],piles[j]);    
        if(dp[i][j]!=-1)
            return dp[i][j];
        int start = piles[i] + min(solve(piles,i+2,j),solve(piles,i+1,j-1));
        int end = piles[j] + min(solve(piles,i+1,j-1),solve(piles,i,j-2));
        
        return dp[i][j]=max(start,end);    
    }
    
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof dp);
        int sum = 0;
        for(int pile :piles)sum+=pile;
        return solve(piles,0,piles.size()-1)*2>=sum;
    }
};
