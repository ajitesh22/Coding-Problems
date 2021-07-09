https://leetcode.com/problems/maximum-length-of-repeated-subarray/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size() , m = nums2.size();
        
        //dp solution  O(N * M) solution
         int dp[n+1][m+1];
        int maxLen = 0;
        for(int i=0;i<n+1;i++)
            for(int j=0;j<m+1;j++)
                dp[i][j] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                maxLen = max(maxLen , dp[i][j]);
            }
        }
        
        return maxLen;
    }
    
    
};
