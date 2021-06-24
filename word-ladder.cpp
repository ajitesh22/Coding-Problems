//https://leetcode.com/problems/word-ladder/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& C) {
            string startWord = beginWord,finalWord = endWord;
    map<string,int> map;
    queue<string>queue;
    
    map.insert({startWord,1});
    //map.insert({finalWord,0});
    for( string key : C){
        map.insert({key,0});
    }
    queue.push(startWord);
    if(map.find(finalWord)==map.end())  
        return 0;
    while(!queue.empty()){
        string word = queue.front();
        queue.pop();
        for(int i=0;i<word.size();i++){
            for(int j=0;j<26;j++){
                if(j==int(word[i]-97))continue;
                string newWord = word.substr(0,i) + char(j+97) + word.substr(i+1,word.size());
                if(map.find(newWord)!=map.end()){
                    if(!map[newWord]){
                        map[newWord] = map[word] + 1;
                        queue.push(newWord);
                    }
                    
                    
                }
           }
        }
    }
    
    return map[finalWord];
    }
};
