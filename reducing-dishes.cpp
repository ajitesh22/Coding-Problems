//https://leetcode.com/problems/reducing-dishes/
class Solution {
public:
    
    int dp[501][501];
    int solve(vector<int>& sat , int idx , int time ,int sum){
        
        int n = sat.size();
        if(idx==n)
            return sum;
        
        if(dp[idx][time]!=-1)
            return dp[idx][time];
        
        int ans = INT_MIN;
        for(int i = idx;i<n;i++){
            
            int x = 0 , y = 0;
            if(sat[i] < 0)
                x = solve(sat , i+1 , time  , sum);
            y = solve(sat , i+1 , time + 1,  sum + sat[i]*time);
            
            ans = max(ans , max(x ,y));
        }
        
        return dp[idx][time] = ans;
       
    }

    int maxSatisfaction(vector<int>& sat) {
        
        
        int n = sat.size();
        
        memset(dp , -1 ,sizeof(dp[0])*(n+1));
        sort(sat.begin() , sat.end());
        
        return solve(sat , 0 , 1 , 0);
        
        
    }
};
