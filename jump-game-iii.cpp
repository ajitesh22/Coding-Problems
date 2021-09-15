//https://leetcode.com/problems/jump-game-iii/
class Solution {
public:
    
    int dp[50001];
    int solve(vector<int>& arr, int index , vector<int>& visited){
        if(index<0 || index>=arr.size())
            return 0;
        if(arr[index]==0)
            return 1;
        if(dp[index]!=-1)
            return dp[index];
        int leftIndex = index - arr[index];
        int rightIndex = index + arr[index];
        int option1 = 0 , option2 = 0;
        visited[index] = 1;
        if(leftIndex>=0 && !visited[leftIndex]){
            option1 = solve(arr , leftIndex , visited);
        }
        if(rightIndex<arr.size() && !visited[rightIndex]){
            option2 = solve(arr , rightIndex , visited);
        }
        
        return  dp[index] = option1 | option2;
        
        
    }
    
    
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        for(int i=0;i<n;i++)
            dp[i] = -1;
        //memset(dp , -1 , sizeof(dp[0])*n);
        vector<int> visited(n , 0);
        return solve(arr , start , visited);
        
    }
};
