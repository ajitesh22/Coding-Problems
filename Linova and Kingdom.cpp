//A. Linova and Kingdom(DIV1) : https://codeforces.com/contest/1336/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
 
vector<ll>adj[1000002];
vector<ll>ans;
ll  dfs(ll u,ll parent,ll level){
    
    ll childNode = 0;
    for(ll child : adj[u]){
        if(child==parent)continue;
        childNode+=dfs(child,u,level+1);  
    }
    ans.push_back(level - childNode);
    return childNode+1;
}
int main() {
    ll n,k,u,v;
    
    //ans.clear();
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll x = dfs(1,-1,0);
    //ans.push_back(1-x);
    sort(ans.begin(),ans.end(),greater <>());
    ll sum = 0;
    for(int i=0;i<k;i++)
        sum+=ans[i];
    cout<<sum<<endl;
    return 0;
}
