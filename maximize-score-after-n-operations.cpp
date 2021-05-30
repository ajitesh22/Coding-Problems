//https://leetcode.com/problems/maximize-score-after-n-operations/
class Solution {
public:
    
    int  solve(vector<int>& nums1 ,vector<int>& nums2 , int i , int mask , vector<int>&dp){
        
        
        if(i==nums1.size())return 0;
        
        int ans = INT_MAX;
        
        if(dp[mask]!=-1)return dp[mask];
        
        for(int j=0;j<nums2.size();j++){
            if(mask & (1<<j))continue;
            int x = nums1[i]^nums2[j];
            ans  = min (ans , x + solve(nums1 , nums2 ,i+1 , mask | (1<<j) , dp));
        }
        
        return dp[mask] = ans;
    }
    
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>dp(16385 , -1);
        int count = 0;
        return solve(nums1 , nums2 , 0 , 0  ,dp);
        
        
    }
};
