#include <bits/stdc++.h>
using namespace std;
/*
Given three integers R, B and W which denote the number of runs, 
balls and wickets. One can score 0, 1, 2, 3, 4, 6 or a wicket in 
a single ball in a cricket match. The task is to count the number
of ways in which a team can score exactly R runs in exactly B balls
with at-most W wickets. Since the number of ways will be large,
print the answer modulo 1000000007.

exactly R 
exactly B 
Atmost W
 */
int R,B,W; 
int dp[1000][100][10]; 
int solve(int r,int b,int w){
    
    if(w>W)return 0;
    if(r>R)return 0;
    if(b>B)return 0;
    if(r==R && b==B)return 1;
    if(dp[r][b][w]!=-1)
        return dp[r][b][w];
    int score0 = solve(r,b+1,w);
    int score1 = solve(r+1,b+1,w);
    int score2 = solve(r+2,b+1,w);
    int score3 = solve(r+3,b+1,w);
    int score4 = solve(r+4,b+1,w);
    int score6 = solve(r+6,b+1,w);
    int wicket = solve(r,b+1,w+1);

    return dp[r][b][w]=score0 + score1 + score2 + score3 + score4 + score6 + wicket;
}

int main() {
    memset(dp,-1,sizeof dp);
    R=40,B=10,W=4;
    int x=solve(0,0,0);
    cout<<x;
	return 0; 
}
