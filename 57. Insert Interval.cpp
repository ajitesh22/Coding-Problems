class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         map<int,int>map;
        for(auto interval : intervals){
            map[interval[0]]++;
            map[interval[1]]--;
        }
        map[newInterval[0]]++;
        map[newInterval[1]]--;
        
        vector<vector<int>>ans;
        int count = 0,s=-1,e;
        for(auto i : map){
            if(s==-1)
                s=i.first;
            count+=i.second;
            if(count==0){
               e=i.first;
               ans.push_back({s,e});
               s=-1; 
            }
        }
        return ans;
        
    }
};





 /*
 
 
    1.  2.   3.  4.  5.  6.  7   8   9.  10.  11.  12. 13. 14   15. 16
    1.  -1.  1.      -1   1. -1  1.      -1.        1.              -1
                 1              -1
 
    
    
    
    
    
 */
