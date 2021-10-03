//https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxJump = nums[0];
        if(nums[0]==0 && nums.size()>1)
            return 0;
        for(int i=1;i<nums.size()-1;i++){
            maxJump--;
            if(maxJump<=0 && nums[i]==0)
                return 0;
            maxJump = max(maxJump , nums[i]);
        }
        return 1;
    }
};
