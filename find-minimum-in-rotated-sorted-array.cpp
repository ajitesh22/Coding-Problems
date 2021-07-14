//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0 , high = n-1;
        
        if(nums[0]<nums[n-1])
            return nums[0];
        
        while(low<high){
            
            int mid = low + (high - low)/2;
            if(nums[mid]>=nums[0]){
                low = mid +1;
            }
            else{
                high = mid;
            }
        }
        
        return nums[low];
        
    }
};
