//https://leetcode.com/problems/constrained-subsequence-sum/
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int n = nums.size() , result = nums[0];
        int dp[n];
        deque<int>dq{0};
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            if(dq.front() + k < i)
                dq.pop_front();
            dp[i] = max(nums[i] , nums[i] + dp[dq.front()]);
            result = max(result , dp[i]);
            while(!dq.empty() && dp[dq.back()]<=dp[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return result;
    }
};
