//https://leetcode.com/problems/partition-array-for-maximum-sum/
class Solution {
public:
    
    int dp[505];
    int solve(vector<int>& arr, int k , int idx){
        
        int n = arr.size();
        if(idx>=n)
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int maxVal = 0 , ans = 0;
        for(int i=1;i<=k;i++){
            if(i + idx - 1< n){
                maxVal = max(maxVal , arr[i + idx - 1] );
                ans = max(ans , i*maxVal + solve(arr , k , idx + i));
            }
        }
    
        return dp[idx] = ans;
        
    }
    
    
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       
        int n = arr.size();
        memset(dp ,-1 , sizeof(dp));
        return solve(arr , k ,0);
        
    }
           
};
