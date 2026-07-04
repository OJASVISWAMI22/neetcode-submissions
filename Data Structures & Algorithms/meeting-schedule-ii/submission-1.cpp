/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),
        [](const Interval& a , const Interval& b){
            return a.start < b.start;
        });

        priority_queue<int,vector<int>,greater<int>>q;
        int room=0;
        for(auto it:intervals){
            if(q.empty()){
                q.push(it.end);
                room++;
            }
            else if(it.start<q.top()){
                room++;
                q.push(it.end);
            }
            else{
                q.pop();
                q.push(it.end);
        }
        }

        return room;
    }
};
