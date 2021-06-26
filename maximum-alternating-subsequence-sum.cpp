//https://leetcode.com/problems/maximum-alternating-subsequence-sum/
#define ll long long int
class Solution {
public:
    ll dp[100001][2];
    ll solve(vector<int>& nums , int idx , int flag ){
        
        if(idx == nums.size())
            return 0;
        
        if(dp[idx][flag]!=-1)
            return dp[idx][flag];
        
        ll taken =  0 , notTaken = 0;
        ll num = nums[idx];
        if(!flag)
            num = -num;
        taken =  num + solve(nums , idx + 1, !flag);
        notTaken =  solve(nums , idx + 1 , flag);
        
        return dp[idx][flag] = max(taken , notTaken);
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        
        int n = nums.size();
        
        memset(dp , -1 , sizeof(ll)*n*2);
        return solve(nums , 0 , 1);
        
        
    }
};
