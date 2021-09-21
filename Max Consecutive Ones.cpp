// Max Consecutive Ones
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size() , maxCnt = 0 , currentCnt = 0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==1)
                currentCnt++;
            if(nums[i]==0)
                currentCnt = 0;   
            maxCnt = max(maxCnt , currentCnt);
        }
        
        return maxCnt;
    }
};
