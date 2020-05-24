#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll dp[10][91][2];
 
vector<ll>num;
ll solve(ll index,ll sum,ll tight){
    
    if(index==num.size())
        return sum;
 
    ll limit = 9;
    if(tight)limit = num[index];
 
    ll ans = 0;
    if(dp[index][sum][tight]!=-1)
        return dp[index][sum][tight];
        
    for(ll i=0;i<=limit;i++){
        if(!tight || i<limit)
            ans+=solve(index+1,sum+i,0);
        else 
            ans+=solve(index+1,sum+i,1);
    }
    return dp[index][sum][tight]=ans;
}
 
void numToArray(ll n){
    num.clear();
    while(n>0){
        num.push_back(n%10);
        n/=10;
    }
    reverse(num.begin(),num.end());
}
 
int main(){
    
    ll a,b;
    while(1){
        cin>>a>>b;
        if(a==-1||b==-1)
            break;
        ll suma , sumb;
        memset(dp,-1,sizeof(dp));
        numToArray(a-1);
        suma=solve(0,0,1);
        memset(dp,-1,sizeof(dp));
        numToArray(b);
        sumb=solve(0,0,1);
        cout<<sumb-suma<<endl;
        
    }
    return 0;
}  
