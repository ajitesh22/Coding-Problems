//https://leetcode.com/problems/climbing-stairs/submissions/
class Solution {
    public int climbStairs(int n) {
        
        Integer oneStepBack = 2;
        Integer twoStepBack = 1;
        Integer currSteps = 0;
        if(n==1)
            return twoStepBack;
        if(n==2)
            return oneStepBack;
        for(int i=3;i<=n;i++){
            currSteps = oneStepBack + twoStepBack;
            twoStepBack = oneStepBack;
            oneStepBack = currSteps;
        }
        
        return currSteps;
    }
}

/*
1 2 3 4 5*/
