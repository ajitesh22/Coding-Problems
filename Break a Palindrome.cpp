//Break a Palindrome
class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        if(palindrome.size()==1)
            return "";
        
        for(int i=0;i<palindrome.size();i++){
            if(palindrome.size()%2!=0 && palindrome.size()/2 == i)
                continue;
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
                
        }
        
        palindrome[palindrome.size() - 1]='b';
        return palindrome;      
    }
};
