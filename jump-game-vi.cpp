//https://leetcode.com/problems/jump-game-vi/
class Solution {
public:
   
    /*
    int dp[100001];
    int solve(vector<int>& nums , int k , int idx , int score){
        
        if(idx==nums.size())
            return score;
        
        if(k<0)
            return INT_MIN;
        
        if(dp[idx]!=INT_MIN)
            return dp[idx];
        
        int takeCurrentNum = INT_MIN, notTakeCurrentNum = INT_MIN;
        takeCurrentNum = solve(nums , k , idx + 1 , score + nums[idx]);
        if(k!=0)
            notTakeCurrentNum = solve(nums , k - 1, idx + 1 , score);
        
        dp[idx] = takeCurrentNum;
        if(k!=0)
            dp[idx] = max(dp[idx] , notTakeCurrentNum);
        
        return dp[idx];
    }
    */
    //DP + MONODEQUE SOLUTION 
    int maxResult(vector<int>& nums, int k) {
        /*for(int i=0;i<nums.size();i++){
            dp[i] = INT_MIN;
        }
        return solve(nums , k , 0 ,  0);*/
        
        int n = nums.size();
        deque<int> dq{0};
        int dp[n];
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            if(dq.front() + k < i)
                dq.pop_front();
            dp[i] = nums[i] + dp[dq.front()];
            while(!dq.empty() && dp[dq.back()]<=dp[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return dp[n-1]; 
    }
};
