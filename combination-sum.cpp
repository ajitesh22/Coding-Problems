//https://leetcode.com/problems/combination-sum/
class Solution {
public:
    
    
    void solve(vector<int>& candidates, int target , vector<vector<int>> &finalList , vector<int> currList , int idx ){
        
        
        if(target==0){
            finalList.push_back(currList);
            return ;
        }
        
        if(idx >= candidates.size() || target < 0)
            return ;
        
        cout<<candidates[idx]<<" ";
        currList.push_back(candidates[idx]);
        solve(candidates , target - candidates[idx] , finalList , currList ,  idx);
        currList.pop_back();
        solve(candidates , target , finalList , currList ,  idx + 1);
         
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> finalList ;
        vector<int> currList ;
        
        solve(candidates, target , finalList , currList , 0);
        return finalList;
        
    }
};
