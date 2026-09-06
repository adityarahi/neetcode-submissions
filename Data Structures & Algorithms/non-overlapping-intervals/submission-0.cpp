bool comp(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] < v2[1]; // sort it on the basis of end time (no start time; why?)
    // because the interval that starts first can also be the one that ends at last,
    // pushing every other interval to become overlapping
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int ans = 0;
        int sv = intervals[0][0], ev = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < ev) ans++;
            else {
                sv = intervals[i][0];
                ev = intervals[i][1];
            }
        }
        return ans;
    }
};