//https://leetcode.com/problems/maximum-number-of-removable-characters/
class Solution {
public:
    
    int check(string s, string p, unordered_map<int,int>& map, int k){
        
        int l = 0 , r = 0 , n = s.size() , m = p.size();
        
        while(l<m && r<n){
            
            int flag = false ;
            if((map.find(r)!=map.end()) && map[r]<=k)
                flag = true;
            
            if(p[l]==s[r] && !flag){
                l++;
            }
            r++;
        }
        
        if(l==m)
            return 1;
        return 0;
            
    }
    
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        unordered_map<int,int> map;
        for(int i=0;i<removable.size();i++){
            map.insert({removable[i] , i});
        }
        
        int n = removable.size();
        
        int low = 0 , high = n - 1;
        
        while(low<=high){
            
            int mid = low  + (high - low)/2;
            if(check(s,p,map,mid))
                low = mid+1;
            else
                high = mid -1;
        }
        
        return low;
 
        
        
        
        
        /*
        
        
         "abcacb"
"ab"
[3,1,0]
"abcbddddd"
"abcd"
[3,2,1,4,5,6]
"abcab"
"abc"
[0,1,2,3,4]
"qobftgcueho"
"obue"
[5,3,0,6,4,9,10,7,2,8]
        
        
        
        
        
        
        
        
        */
        
        
        
    }
};
