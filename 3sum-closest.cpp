//https://leetcode.com/problems/3sum-closest/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0 ,r = n-1;
        
        int ans = nums[0] + nums[1] + nums[2];
        for(int i=0;i<n;i++){
            int l = i+1 ,r = n-1;
            while(l<r){
                int tripletSum = nums[i] + nums[l] + nums[r];
                if(abs(tripletSum - target) < abs(ans - target)){
                    ans = tripletSum;
                }
                if(ans == target)
                    break;
                if(tripletSum > target)
                    r--;
                else
                    l++;
            }
        }
        
        return ans;
        
    }
};
