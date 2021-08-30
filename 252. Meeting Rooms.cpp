
//https://www.lintcode.com/problem/meeting-rooms/description

/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
         map<int,int>map;
        for(auto interval : intervals){
            
            map[interval.start]++;
            map[interval.end]--;
        }
        int count = 0,ans=0;
        for(auto i : map){
             count+=i.second;
             if(count>1)return false;
            }
        return true;
    }
};
