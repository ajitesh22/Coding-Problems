/*
Find out the number of A digit positive numbers, whose digits on being added equals to a given number B. 
Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed. 
Since the answer can be large, output answer modulo 1000000007

Problem Constraints
1 <= A <= 1000 1 <= B <= 10000  
*/
#define MOD 1000000007
int dp[1002][10002];
int n,reqSum;
int solve1(int index,long long int sum){
    if(index==n){
        if(reqSum==sum)
            return 1;
        else
            return 0;    
    }
    if(dp[index][sum]!=-1)
        return dp[index][sum];
    long long int ans = 0;
    for(int i=0;i<=9;i++){
        if(i==0 && index==0)continue;
        ans += solve1(index+1,sum+i);
    }
    return dp[index][sum]=(ans%MOD);
    
}


int Solution::solve(int A, int B) {
    memset(dp,-1,sizeof(dp));
    n=A;reqSum=B;
    long long int sum=0;
    return solve1(0,0)%MOD;
}
