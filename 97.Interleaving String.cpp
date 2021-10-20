class Solution {
public:
    string s1,s2,s3;
    map<string,int>dp;
    int solve(int i,int j,int k){
        
        if(i==-1 && j==-1 && k==-1)return 1;
        if(i==-1 && j==-1 && k>=0)return 0;
        if((i>=0 || j>=0) && k==-1)return 0;
        
        string key = to_string(i)+":"+to_string(j)+":"+to_string(k);
        
        if(dp.find(key)!=dp.end())
            return dp[key];
        char c = s3[k];
        int x=0,y=0;
        if(i>=0 && s1[i]==c)
             x = solve(i-1,j,k-1);
        if(j>=0 && s2[j]==c)
             y = solve(i,j-1,k-1);
   
        return dp[key]=x||y;
    }
    
    
    bool isInterleave(string S1, string S2, string S3) {
        
        s1=S1;s2=S2;s3=S3;
        dp.clear();
        return solve(s1.size()-1,s2.size()-1,s3.size()-1);
    }
};
