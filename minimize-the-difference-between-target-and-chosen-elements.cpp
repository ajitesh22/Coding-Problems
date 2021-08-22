//https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/
class Solution {
public:
    
    int dp[10000][80];
    int dfs(vector<vector<int>>& mat, int target , int currSum , int row){
        
        if(row>=mat.size())
            return abs(target - currSum);
        
        if(dp[currSum][row]!=-1)
            return dp[currSum][row];
        
        int ans = INT_MAX;
        for(int i=0;i<mat[row].size();i++){
            ans = min(ans , dfs(mat , target , currSum + mat[row][i] , row + 1));
        }
        return dp[currSum][row] = ans;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp , -1 , sizeof(dp));
        return dfs(mat , target , 0 , 0 );
    }
};
