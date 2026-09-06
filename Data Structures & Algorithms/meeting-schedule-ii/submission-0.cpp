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
        int n = intervals.size();
        vector<int> st(n), end(n);
        int rooms = 0;
        for(int i = 0; i < n; i++) {
            st[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }
        sort(st.begin(), st.end());
        sort(end.begin(), end.end());
        int i = 0, j = 0;
        while(i < n) {
            if(st[i] >= end[j]) {
                rooms--; j++;
            }
            rooms++; i++;
        }
        return rooms;
    }
};
