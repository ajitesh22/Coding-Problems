//https://leetcode.com/problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
       int n=nums.size(), num = nums.size(); 
       for(int i=0;i<n;i++){
           num^=i;
           num^=nums[i];
       }
        
        return num;
    }
};
