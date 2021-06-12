//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
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
                windowSum-=cardPoints[i];
             if(j<n)
                windowSum+=cardPoints[j];
             i++;
         }
             
         return ans;
    }
};
