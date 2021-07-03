//https://leetcode.com/problems/beautiful-arrangement/
class Solution {
public:
    
    int solve(int N, int  idx , int mask){
    
        if(idx>N)
            return 1;
           
        int opt1 = 0;
        for(int i=1;i<=N;i++){

            int currMask = 1<<(i);
            if((!(idx%i) || !(i%idx)) && !(mask & currMask))
                opt1 += solve(N , idx+1 ,mask | currMask);
        }
        return opt1 ;
    }
    
    int countArrangement(int N) {
        
        return solve(N,1,0);
    }
};
