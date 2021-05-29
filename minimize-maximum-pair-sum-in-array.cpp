//https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        
        int minv = INT_MIN;
        
        int l = 0 , r = nums.size() -1 ;
        
        while(l<=r){
            
            minv=max(minv , nums[l]+nums[r]);
            l++;r--;
        }
        
        return minv;
    }
};
