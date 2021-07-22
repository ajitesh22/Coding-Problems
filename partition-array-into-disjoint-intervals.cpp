//https://leetcode.com/problems/partition-array-into-disjoint-intervals/
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>maxSoFar(n+1,-1);
        maxSoFar[0] = nums[0];
        for(int i=1;i<n;i++){
            maxSoFar[i] = max(nums[i] , maxSoFar[i-1]);
        }
        
        int idx , minSoFar = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(minSoFar>=maxSoFar[i])
                idx = i;
            minSoFar = min(minSoFar , nums[i]);
        }
        
        return idx+1;
        
    }
};
