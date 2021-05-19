//https://leetcode.com/problems/minimum-window-substring
class Solution {
public:
    
    string minWindow(string s, string t) {
        
        int n = s.size();
       
        map<char,int>map;
        int count = t.size();
        for(int i = 0; i<t.size() ;i++)
            map[t[i]]++;
        
        int left = 0 , right = -1 , index = -1 , minLength = INT_MAX;
        
        while(right<n-1){
            right++;
            if(map.find(s[right])!=map.end()){
                if(map[s[right]]>0)
                    count--;
                map[s[right]]--;
            }
            
            while(count<=0){
                if(map.find(s[left]) != map.end()){
                    map[s[left]]++;
                    if(map[s[left]]>0)
                        count++;
                }
                if(minLength > right- left + 1){
                    minLength = right -left + 1;
                    index = left;
                }
                left++;
            }
        }
        
        
        if(index==-1)
            return "";
        return  s.substr(index , minLength);
        
    }
};
