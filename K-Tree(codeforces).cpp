/*
  https://codeforces.com/problemset/problem/431/C

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
//int dp[10000][2];
//int n,k,d;
/*int solve(int sum,int flag){
    
    if(sum>n)return 0;
    if(sum==n){
        if(flag)return 1;
        return 0;
    }
    if(dp[sum][flag]!=-1)
        return dp[sum][flag];
    int ans = 0;dp[sum][flag]=0;
    for(int i=1;i<=k;i++){
        flag|=((i>=d)?1:0);
        ans+=solve(sum+i,flag);
    }
    
    return dp[sum][flag] += ans;
}*/
int main() {
    int n,k,d;
    cin>>n>>k>>d;
    
    //dp[0][0]=1;
    //int  x=solve(0,0);
    
    int dp[n+1][2];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            ll x= (i-j>=0)?dp[i-j][0]:0;
            ll y = (i-j>=0)?dp[i-j][1]:0;

            if(j>=d){
                dp[i][1] = (dp[i][1]+x + y + MOD)%MOD;
            }
            else{
                dp[i][0] = (dp[i][0]+ x + MOD)%MOD;
                dp[i][1] = (dp[i][1]+ y + MOD)%MOD;
            }
        }
    }
    
   /* for(int i=0;i<=n;i++){
        for(int j=0;j<2;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    
    
    cout<<dp[n][1]<<endl;

	return 0;
}
