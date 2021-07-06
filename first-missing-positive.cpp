//https://leetcode.com/problems/first-missing-positive/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            
            int flag = 1;
            while(flag){
                int x = nums[i];
                if(x>0 && x<n && x-1!=i && nums[i]!=nums[x-1]){
                    swap(nums[i] , nums[x-1]);
                }
                else{
                    flag = 0;
                }
            }
            
        }
        
        
        for(int i=0;i<n;i++){
            if(i+1!=nums[i])
                return i+1;
        }
        
      return n+1;  
    }
};


    
