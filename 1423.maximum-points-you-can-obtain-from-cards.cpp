//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// recursion  +  memoisation  ---->TLE  O(N*K)     



class Solution {
public:
    
    vector<vector<int>> dp;
    int solve(vector<int>& cardPoints , int k ,int currPoints , int i ,int j){
        
        int n = cardPoints.size();
        if(k==0)
            return currPoints;
        if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int currSum = 0;
        currSum = solve(cardPoints, k-1,currPoints + cardPoints[i] , i+1 , j);
        currSum = max(currSum , solve(cardPoints, k-1,currPoints + cardPoints[j] , i , j - 1));
    
        return dp[i][j] = currSum ;
    }
    
    int maxScore(vector<int>& cardPoints, int k) {
         
         dp = vector<vector<int>>(cardPoints.size() + 1 , vector<int>(cardPoints.size() + 1 , -1) );   
         int currPoints = 0;
         return solve(cardPoints , k , currPoints , 0 , cardPoints.size() - 1);
    }
};





//  sliding window technique  -----> O(N) where N is number of elements in the array and  K is number of element to be picked

class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
         
         int n = cardPoints.size(); 
         int sum = 0 ;  
         for(int i=0;i<n;i++){
             sum += cardPoints[i];
         }
         int windowSum = 0; 
         for(int i=0;i<= n - k - 1 ;i++)
             windowSum += cardPoints[i];
         
         int i=0 , j = n - k - 1 , ans = 0; 
         while(j<n){
             ans = max(ans , sum - windowSum);
             j++;
             //if(i<n)
                windowSum-=cardPoints[i];
             if(j<n)
                windowSum+=cardPoints[j];
             i++;
         }
          
         return ans;
    }
};
