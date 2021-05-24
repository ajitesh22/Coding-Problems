//https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {    


        int  n = s.size() , left = 0 ,right = -1  , maxLength = 0 ;
        int freq[257] = {0};

        while(right<n-1){

            right++;
            freq[s[right]]++;
            
            while(freq[s[right]]>1){
                freq[s[left]]--;
                left++;

            }
            
            maxLength = max(maxLength , right - left + 1);

        }

        return maxLength ;

        
    }
};
