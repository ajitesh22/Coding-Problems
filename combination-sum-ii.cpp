//https://leetcode.com/problems/combination-sum-ii
class Solution {
public:
    
    set<string>set;
    string vectorToKey(vector<int>arr){
        string key = "";
        for(int e : arr){
            key += std :: to_string(e)  +  std :: to_string(':') ;
        }
        return key;
    }
    
    void solve(vector<int>& candidates, vector<vector<int>> &ans ,  vector<int> &curr ,int idx ,int target){
        
        if(target < 0)
            return ;
        
        if(target==0){
            string key = vectorToKey(curr);
            if(target==0 && !set.count(key)){
                ans.push_back(curr);
                set.insert(key);
            }
            return;
        }
        if(idx==candidates.size())
            return;
        
        curr.push_back(candidates[idx]);
        solve(candidates , ans , curr , idx+1 , target - candidates[idx]);
        curr.pop_back();
        solve(candidates , ans , curr , idx+1 , target);
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> andidates;
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        
        solve(candidates , ans , curr , 0 , target);
        return ans;
        
    }
};
