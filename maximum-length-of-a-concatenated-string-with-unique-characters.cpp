//https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
class Solution {
public:
    
    int CanTakeCurrentWord(string word , int mask){
        for(char c : word){
            int n = c - 'a';
            if(mask & (1<<n))
                return -1;
            mask |= (1<<n); 
        }
        return mask;
    }
    
    int countSetBits(int n)
    {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    
    int solve(vector<string>& arr , int mask , int index){
        
        if(index==arr.size())
            return countSetBits(mask);
        
        int takeCurrentWord=0 , notTakeCurrentWord = 0; 
        int newMask = CanTakeCurrentWord(arr[index] , mask);
        if(newMask!=-1)
            takeCurrentWord = solve(arr , newMask , index + 1);
        notTakeCurrentWord = solve(arr , mask , index + 1);
    
        return max(takeCurrentWord , notTakeCurrentWord);    
        
    }
    
    
    int maxLength(vector<string>& arr) {
        
        return solve(arr , 0 , 0); 
    }
};
