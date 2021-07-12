https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        set<string>used;
        map<int,int>suffix;
        map<int,int>prefix;
        
        for(int i=0;i<s.size();i++){
            int c = s[i] - 'a';
            if(prefix.find(c)==prefix.end()){
                prefix.insert({c,i});
            }
        }
        
        for(int i=s.size() - 1;i>=0;i--){
            int c = s[i] - 'a';
            if(suffix.find(c)==suffix.end()){
                suffix.insert({c,i});
            }
        }
        
        int cnt = 0 ;
        for(int i=0;i<s.size();i++){
            int c = s[i] - 'a';
            for(int j=0;j<26;j++){
                int idx1 = -1 , idx2 = -1;
                if(prefix.find(j)!=prefix.end())
                    idx1 = prefix[j];
                if(suffix.find(j)!=suffix.end())
                    idx2 = suffix[j];
                string key = to_string(j) +":"+ to_string(c) + ":" + to_string(j) ;
                //cout<<key<<" ";
                if(idx1==-1 || idx2==-1 || idx1>=i || idx2<=i || used.count(key))
                    continue;
                
                //cout<<key<<" ";
                used.insert(key);
                cnt++;
            }
            
        }
        
        return cnt++;
        
    }
};
