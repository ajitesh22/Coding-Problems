//https://leetcode.com/problems/minimum-absolute-difference-queries/
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(101 , 0));
        
        for(int i=0;i<n;i++){
            
            dp[i][nums[i]]++;
            for(int j=0;j<=100;j++){
                if(i!=0)
                    dp[i][j]+=dp[i-1][j];
            }
            
        }
        
        //answering queries 
        
        vector<int> res;
        
        for(int i=0;i<queries.size();i++){
            int  l = queries[i][0] , r = queries[i][1];
            vector<int>freq;
            for(int j=0;j<=100;j++){
                int count = dp[r][j];
                if(l!=0)
                    count -= dp[l-1][j];
                freq.push_back(count);
            }
            int minDiff = INT_MAX , idx = -1; 
            for(int j=1;j<=100;j++){
                
                if(idx!=-1){
                    if(freq[j]!=0)
                        minDiff = min(minDiff , abs(j - idx));
                }
                
                if(freq[j]!=0)
                    idx = j;
                    
            }
            
            if(minDiff==INT_MAX)
                minDiff = -1;
            res.push_back(minDiff);
            
            
        }
        
        return res;
        
    }
};
