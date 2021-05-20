class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        
        int  n = s.size();
        int distCharCount  = 0;
        int freq[126] = {0};

        int left = 0 , right = - 1 , maxLength = 0 ;

        while(right < n - 1){
            right++;
            freq[s[right]]++;
            if(freq[s[right]]==1){
                distCharCount++;
            }

            while(distCharCount > k){
                if(freq[s[left]]==1){
                    distCharCount--;   
                }
                freq[s[left]]--;
                left++;
            }

            maxLength = max(maxLength , right - left  + 1);
        }

        return maxLength;
    }
};
