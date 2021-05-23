//https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/
class Solution {
public:
    bool checkZeroOnes(string s) {
        
        int n = s.size(), one = 0, zero =0 ,curr =0;
        
        for(int i=0;i<n;i++){
            if(i==0){
                if(s[i]=='0')
                    curr++;
            }
            else{
                if(s[i] == '0')
                    curr++;
                else{
                    zero = max(zero ,curr);
                    curr =0;
                }
            }
        }
        zero = max(zero ,curr);
       // cout<<zero<<" ";
        curr =0;
         for(int i=0;i<n;i++){
            if(i==0){
                if(s[i]=='1')
                    curr++;
            }
            else{
                if( s[i] == '1')
                    curr++;
                else{
                    one = max(one ,curr);
                    curr = 0;
                }
            }
        }
        one = max(one ,curr);
        //cout<<one <<" "<<zero<<" ";
        if(one>zero)
            return true;
        return false;
        
 
    }
};
