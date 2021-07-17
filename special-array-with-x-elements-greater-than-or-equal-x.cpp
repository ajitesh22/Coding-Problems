//https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt[1001] = {0};
        
        for(int num : nums){
            cnt[num]++;
        }
        for(int i=1;i<1001;i++)
            cnt[i]+=cnt[i-1];
        
        for(int i=1;i<1001;i++){
            if(n - cnt[i-1]==i)
                return i;
        }
        
        return -1;
    }
};
