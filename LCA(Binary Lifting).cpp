#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
const int maxN = 11;
vector<ll>adj[1000002];
int level[1001],LCA[1001][maxN+1];
void  dfs(ll u,ll par,ll l){
    level[u]=l;
    LCA[u][0]=par;
    for(ll c : adj[u]){
        if(c==par)continue;
        dfs(c,u,l+1);
    }
}
void init(int n){
    dfs(1,-1,0);
    for(int i=1;i<=maxN;i++){
        for(int j=1;j<=n;j++){
            if(LCA[j][i-1]!=-1)
                LCA[j][i]=LCA[LCA[j][i-1]][i-1];
        }
    }
}

int getLCA(int a,int b){
    if(level[b]<level[a])swap(a,b);
    int d = level[b] - level[a];
    while(d>0){
        int i=log2(d);
        b=LCA[b][i];
        d-=1<<i;
    }
    if(a==b)return a;
    for(int i=maxN;i>=0;i--){
        if(LCA[a][i]!=-1 && LCA[a][i]!=LCA[b][i])
            {a=LCA[a][i];b=LCA[b][i];}
    }
    return LCA[a][0];
}
int main() {
    ll n,a,b,u,v;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(LCA,-1,sizeof(LCA));
    dfs(1,-1,0);
    init(n);
    cout<<getLCA(2,8);
    
    return 0;
}
