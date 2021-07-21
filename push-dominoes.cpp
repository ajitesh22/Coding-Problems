//https://leetcode.com/problems/push-dominoes/
class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n = dominoes.size();
        int left[n] , right[n];
        
        right[0] = (dominoes[0]=='R')? 0 : n;
        for(int i=1;i<n;i++){
            if(dominoes[i]=='L'){
                right[i] = n;
            }
            if(dominoes[i]=='R'){
                right[i] = 0;
            }
            if(dominoes[i]=='.'){
                right[i] = min(n,right[i-1]+1);
            }
            
        }
        
        left[n-1] = (dominoes[n-1]=='L')? 0 : n;
        for(int i=n-2;i>=0;i--){
            if(dominoes[i]=='R'){
                left[i] = n;
            }
            if(dominoes[i]=='L'){
                left[i] = 0;
            }
            if(dominoes[i]=='.'){
                left[i] = min(n,left[i+1]+1);
            }
            
        }
        
        for(int i=0;i<n;i++){
            if(dominoes[i]=='.'){
                if(left[i]==right[i])
                    continue;
                if(left[i]<right[i])
                    dominoes[i]='L';
                else
                    dominoes[i]='R';
            }
        }
        
        return dominoes;
        
    }
};

/*

L......L - all state changes to L
L......R - middle state remains same
R......L - half changes to R and half changes to L
R......R - all state changes to R

L.....   - stays same

R.....   -  All R

.....L   -  All L

.....R   -  stays same


*/
