//https://leetcode.com/problems/guess-number-higher-or-lower
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        int l = 0 , r = n;
        
        while(l<r){
            int m = l + (r - l)/2;
            int g = guess(m);
            if(g==0)
                return m;
            if(g>0)
                l=m+1;
            else
                r=m;
        }
        
        return l;
    }
};
