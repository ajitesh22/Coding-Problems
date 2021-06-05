//https://leetcode.com/problems/stone-game-vi/

//Greedy
class Solution {
public:
    
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        
        int n = aliceValues.size();
        vector<vector<int>> sumArray;
        
        for(int i=0;i<n;i++){
            sumArray.push_back({aliceValues[i] + bobValues[i] , aliceValues[i]  , bobValues[i]});
        }
        
        sort(sumArray.begin(),sumArray.end() , greater<vector<int>>());
        
        int scoreA = 0 , scoreB = 0;
        
        for(int i=0;i<n;i++){
            
            if(i%2==0)
                scoreA += sumArray[i][1];
            else
                scoreB += sumArray[i][2];
        }
    
        
        if(scoreA > scoreB)
            return 1;
        if(scoreA == scoreB)
            return 0;
        return -1;
        
        
        
        
    }
};
