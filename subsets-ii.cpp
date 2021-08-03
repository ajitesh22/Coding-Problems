https://leetcode.com/problems/subsets-ii/
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
    
    void solve(vector<int>& nums , vector<int> curr , vector<vector<int>> &ans , int idx){
        
        if(idx==nums.size()){
            string key = vectorToKey(curr);
            
            if(!set.count(key)){
                ans.push_back(curr);
                set.insert(key);
            }
            return ;
        }
        
        curr.push_back(nums[idx]);
        solve(nums,curr,ans,idx+1);
        curr.pop_back();
        solve(nums,curr,ans,idx+1);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        set.clear();
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        solve(nums,curr,ans,0);
        
        return ans;
    }
};

//"1 : 2 : 2"
