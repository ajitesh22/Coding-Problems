
//https://www.lintcode.com/problem/meeting-rooms-ii/description

**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
#include<bits/stdc++.h>
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        map<int,int>map;
        for(auto interval : intervals){
            
            map[interval.start]++;
            map[interval.end]--;
        }
        int count = 0,ans=0;
        for(auto i : map){
             count+=i.second;
             ans=max(ans,count);
            }
        return ans;
    }
};
