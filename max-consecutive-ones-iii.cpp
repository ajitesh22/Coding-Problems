//https://leetcode.com/problems/max-consecutive-ones-iii/
class Solution {
public:
    
    
    int longestOnes(vector<int>& nums, int k) {
        
        int l = 0 , r = -1 , flips = k  , cnt = 0 , ans = 0 , n = nums.size();
        while(r < n-1){
            r++;
            if(nums[r]==0){
                flips--;
                while(flips<0){
                        if(nums[l]==0)
                            flips++;
                        l++;
                    }
            }
            if(flips>=0)
                ans = max(ans , r - l +1);   
        }
        return ans;
    }
};
