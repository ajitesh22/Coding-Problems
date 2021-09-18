//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
class Solution {
public:
    
    int check(vector<int>& bloomDay, int m, int k , int currDay){
        
        int cnt = 0 ;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=currDay)
                cnt++;
            else
                cnt=0;
            if(cnt==k){
                m--;
                cnt=0;
            }
                
            if(m==0)
                return 1;
        }
        
        return 0;   
    }
    
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        //Binary Search on search space [1 , 10^9]
        
        int lo = 1 , hi = 1000000000 , res = -1;
        
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            if(check(bloomDay , m , k ,mid)){
                hi = mid - 1;
                res = mid;
            }
            else
                lo = mid + 1;  
        }
        
        
        return res;
        
    }
};
