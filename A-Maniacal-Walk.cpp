//https://binarysearch.com/problems/A-Maniacal-Walk
#define mod 1000000007
long long int dp[1001][501];
int steps(int length , int idx , int n ){

    if(idx<0 || idx>=length)
        return 0;
    if(n==0 && idx==0)
        return 1;
    if(n<=0 && idx!=0)
        return 0;
    if(dp[idx][n]!=-1)
        return dp[idx][n];
    long long int x = steps(length , idx + 1 , n -1);
    long long int y = steps(length , idx     , n -1);
    long long int z = steps(length , idx - 1 , n -1);
    cout<<idx<<" ";
    return dp[idx][n] = (x+y+z)%mod;

}

int solve(int length, int n) {
    memset(dp , -1 ,sizeof dp);
    return steps(length , 0 , n)%mod;
}
