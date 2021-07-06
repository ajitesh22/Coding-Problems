//https://leetcode.com/problems/combinations/
class Solution {
public:
    
   void solve(vector<vector<int>> &ans , vector<int> &curr ,int n , int k){
        
        if(k==0 && n>=0){
            ans.push_back(curr);
            return ;
        }
        
        if(n<=0){
            return;
        }
       
        curr.push_back(n);
        solve(ans , curr , n - 1, k-1);
        curr.pop_back();
        solve(ans , curr , n - 1 ,k);

    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans,curr,n,k);
        return ans;
        
    }
};
