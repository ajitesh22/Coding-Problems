
//https://leetcode.com/problems/combination-sum-iii/
class Solution {
public:
    
    void solve(int k , int n ,int idx ,vector<int>currList , vector<vector<int>> &finalList){
        
        if((k==0 && n>0) || (k!=0 && n<=0) || idx>9)
            return ;
        
        if(k==0 && n==0){
            finalList.push_back(currList);
            return;
        }
            currList.push_back(idx);
            solve(k-1, n-idx, idx + 1 , currList , finalList);
            currList.pop_back();

    }    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int>currList ;
        vector<vector<int>>finalList;
        solve(k, n , 1 ,currList , finalList);
        
        return finalList;
        
    }
};
