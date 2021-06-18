//https://leetcode.com/problems/delete-and-earn/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int dp[10001] = {0};
        int freq[10001] = {0};
        int maxElement = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            maxElement = max(maxElement , nums[i]);
        }
        
        dp[1] = freq[1];
        for(int i=2;i<=maxElement;i++){
            dp[i] = dp[i-1];
            if(freq[i]){
                dp[i] = max(dp[i] , dp[i-2] + i*freq[i]);
            }
        }
        
        return dp[maxElement];  
    }
};
