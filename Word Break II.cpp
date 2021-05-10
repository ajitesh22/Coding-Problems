//https://leetcode.com/problems/word-break-ii/
class Solution {
public:
    
    string vectorToString(vector<string> &currPartition){

        string s="";
        for(string c : currPartition)
            s+=c+" ";
        return s.substr(0,s.size()-1);
    }
    
    void solve(string s ,int idx , map<string,int> &map, vector<string> &currPartition, vector<string> &allPartitions){
        
        if(idx == s.size()){
            string newStr = vectorToString(currPartition);
            allPartitions.push_back(newStr);
            return;
        }

        for(int i=idx;i<s.size();i++){
            if(map.find(s.substr(idx,i+1-idx))!=map.end() && map[s.substr(idx,i+1-idx)]){
                //map[s.substr(idx,i+1-idx)]--; uncomment this if you are not allowed to reuse a dictionary word 
                currPartition.push_back(s.substr(idx,i+1-idx));
                solve(s,i+1,map,currPartition,allPartitions);
                currPartition.pop_back();
                //map[s.substr(idx,i+1-idx)]++; uncomment this if you are not allowed to reuse a dictionary word 
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        vector<string>allPartitions;
        vector<string>currPartition;
        map<string,int>map;
        
        for(int i=0;i<wordDict.size();i++){
            map[wordDict[i]]+=1;
        }
        solve(s,0,map,currPartition,allPartitions);
        
        return allPartitions;
        
    }
};
