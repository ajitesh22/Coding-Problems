//https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    
    int jump(vector<int>& nums) {
        
        if(nums.size()==1)
            return 0;
        
        int minJump = 1;
        int currMaxJump = nums[0] - 1;
        int stepsLeft = nums[0] - 1;
        
        for(int i=1;i<nums.size() - 1;i++){
            
            if(stepsLeft==0){
                currMaxJump = max(currMaxJump , nums[i]);
                stepsLeft = currMaxJump;
                minJump++;
            }
            else{
                currMaxJump = max(currMaxJump , nums[i]);
            }
            currMaxJump--;
            stepsLeft--;
        }
        return minJump;
    }
};


/*

[2,3,1,1,4]
mj = 1
cmj = 1
sl = 1

num = 3
mj = 1
cmj = 2
sl = 0


num = 1
mj = 1
cmj = 2
sl = 2

mj = 2
cmj = 1
















*/
