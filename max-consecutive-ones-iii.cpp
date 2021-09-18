//https://leetcode.com/problems/max-consecutive-ones-iii/
class Solution {
public:
    
    int check(vector<int> &ps , int windowSize , int k){
        
        if(ps.size()==windowSize){
            if(ps[ps.size()-1]<=k)
                return 1;
            else
                return 0;
        }
        
        for(int i=0;i<ps.size() - windowSize;i++){
            if(ps[i+windowSize] - ps[i]<=k)
                return 1;
        }
        return 0;
    }
    
    
    
    int longestOnes(vector<int>& nums, int k) {
        
      /*  
      //SLIDING WINDOW APPROACH
      int l = 0 , r = -1 , flips = k  , cnt = 0 , ans = 0 , n = nums.size();
        while(r < n-1){
            r++;
            if(nums[r]==0){
                flips--;
                while(flips<0){
                        if(nums[l]==0)
                            flips++;
                        l++;
                    }
            }
            if(flips>=0)
                ans = max(ans , r - l +1);   
        }
        return ans; */
        
        //BINARY SEARCH 
        int lo = 0 , hi = nums.size() , ans = 0 , n = nums.size() ,cnt = 0 ;
        vector<int> ps(n , 0);
        ps[0] = (nums[0]==0) ? 1 : 0;
        for(int i=1;i<n;i++){
            ps[i] =  ps[i - 1] + ((nums[i]==0) ? 1 : 0);
        }
        
        while(lo<=hi){
           int mid = lo + (hi - lo)/2;
            cout<<mid<<" ";
           if(check(ps , mid , k)){
                lo = mid + 1;
                ans = mid;
            }     
            else
               hi = mid - 1;
            }
        return  ans;
            
    
        
    }
    
};
