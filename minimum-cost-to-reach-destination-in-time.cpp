//https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/
class Solution {
public:
    
    int dp[1001][1001];

    int solve(int maxTime,  vector<pair<int,int>> adj[], vector<int> &passingFees ,int node , int currTime ,int target){
        
        if(node == target)
            return passingFees[node];
        
        if(dp[node][currTime]!=-1)
            return dp[node][currTime];
        
        int ans = 10000000;
        for(auto c : adj[node]){
            int cnode = c.first , time = c.second;
            if(currTime + time <= maxTime)
                ans = min(ans ,passingFees[node] + solve(maxTime , adj , passingFees , cnode , currTime + time , target));
            
        }
        
        return dp[node][currTime] = ans ;
        
    }
    
    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        
        int n = passingFees.size();
        memset(dp , -1 , sizeof(dp));
        vector<pair<int,int>> adj[n+1];
        for(auto edge : edges){
            adj[edge[0]].push_back({edge[1] , edge[2]});
            adj[edge[1]].push_back({edge[0] , edge[2]});
        }
        
        int ans = solve(maxTime, adj , passingFees , 0 , 0 , n-1) ;
        return (ans  < 10000000 )? ans : -1;
    
    }
};
