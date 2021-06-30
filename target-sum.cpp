//https://leetcode.com/problems/target-sum/
class Solution {
public:
    int dp[25][20001][2];
    int solve(vector<int>& nums,int idx , int target){
        
        if(idx == nums.size()){
            if(target == 0)
                return 1;
            return 0;
        }
        
        
        int col = (target>=0)? 0 : 1;
        
        if(dp[idx][abs(target)][col]!=-1)
            return dp[idx][abs(target)][col];
        
        int opt1 = 0 , opt2 = 0 ;
        opt1 = solve(nums , idx + 1 , target - nums[idx]);
        opt2 = solve(nums , idx + 1 , target + nums[idx]);
        
        return dp[idx][abs(target)][col]= opt1 + opt2;
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        

        for(int i=0;i<25;i++)
            for(int j=0;j<20001;j++)
                for(int k=0;k<2;k++)
                    dp[i][j][k] = -1;
        return solve(nums , 0 , target);
    }
};
