bool comp(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] < v2[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int sv = intervals[0][0], ev = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(ev >= intervals[i][0]) {
                ev = max(ev, intervals[i][1]);
            }
            else {
                ans.push_back({sv,ev});
                sv = intervals[i][0];
                ev = intervals[i][1];
            }
        }
        ans.push_back({sv, ev});
        return ans; 
    }
};