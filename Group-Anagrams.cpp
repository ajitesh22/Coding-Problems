//Group Anagrams
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& words) {
        
        vector<vector<string>> ans;
        map<string , vector<string>> groupWordsMap;
        
        for(string word : words){
            string sortedWord = word;
            sort(sortedWord.begin() ,sortedWord.end());
            groupWordsMap[sortedWord].push_back(word);
        }
        
        for(auto groupWords : groupWordsMap){
            ans.push_back(groupWords.second);
        }
        return ans;
    }
};
