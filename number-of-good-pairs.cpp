//https://leetcode.com/problems/number-of-good-pairs/
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        map<int,int>map;
        int cnt = 0;
        for(int num : nums){
            if(map.count(num)>0)
                cnt+=map[num];
            map[num]++;
        }
        return cnt;
        
    }
};
