class Solution {
public:
  bool isPossible(string s,vector<string>& wordDict,vector<int> &dp){
        int n=s.size();
        if(n==0)
            return true;
        if(dp[n]==-1){
        dp[n]=0;
        for(int index=1;index<=s.size();index++){
            if(find(wordDict.begin(),wordDict.end(),s.substr(0,index))!=wordDict.end())
                if(isPossible(s.substr(index),wordDict,dp))
                    return dp[n]=1;
            }
        }
        return dp[n];   
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1,-1);
        isPossible(s,wordDict,dp);
        return dp[s.size()];
        
    }
  /*  bool wordBreak(string s, vector<string>& wordDict) {
         if(s.size()==0){
            return true;
        }
        for(int index=1; index<=s.size(); index++){
            if(find(wordDict.begin(),wordDict.end(),s.substr(0,index))!=wordDict.end())
                if (wordBreak(s.substr(index),wordDict))
                    return true;
        }
        return false;     
    }*/
};
