//https://leetcode.com/problems/number-of-ways-to-split-a-string/
class Solution {
public:
    int numWays(string s) {
        long long int mod = 1000000007;
        int cntOnes = 0;
        for(char c : s)
            cntOnes += (c=='1')? 1 : 0;

        if(cntOnes%3!=0)
            return 0;
        if(cntOnes==0){
            return (((s.size()-2)*(s.size()-1))/2)%mod;
        }

        map<int , int>freqMap;
        int cnt = 0;
        for(int i=0;i<s.size()-1;i++){
            cnt += (s[i]=='1')? 1 : 0;  
            freqMap[cnt]++;
        }
        cnt=0;
        long long int ans = 0;
        for(char c : s){
            cnt += (c=='1')? 1 : 0;  
            if(cnt == (cntOnes/3) && freqMap.count(cnt*2)>0)
                ans += freqMap[cnt*2];    
        }
        return ans%mod;
    }
};
