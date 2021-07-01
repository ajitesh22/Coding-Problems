//https://leetcode.com/problems/frequency-of-the-most-frequent-element/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long int left = 0 , right = -1 , maxFreq = 0 ;
        long long int sum = 0;

        while(right < n-1){
            long long int remOpr = k;
            right++;
            sum+=nums[right]; 
            long long int reqOpr = nums[right] * (right - left + 1); 
            remOpr-=(reqOpr - sum);

            while(remOpr<0){
                remOpr+=(nums[right] - nums[left]);
                sum-=nums[left];
                left++;
            }
            maxFreq = max(maxFreq , right - left + 1); 
        }
        
        return maxFreq;   
    }
};
