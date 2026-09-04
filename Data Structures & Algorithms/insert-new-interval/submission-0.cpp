class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int new_st = newInterval[0], new_end = newInterval[1], merged = 0;
        vector<vector<int>> ans;
        for(vector<int>& intrvl : intervals) {
            if(intrvl[1] < new_st) ans.push_back(intrvl);
            else {
                if(new_end < intrvl[0]) {
                    if(!merged) {
                        ans.push_back({new_st, new_end});
                        merged = 1;    
                    }
                    ans.push_back(intrvl);
                }
                else {
                    new_st = min(new_st, intrvl[0]);
                    new_end = max(new_end, intrvl[1]);
                }
            }
        }
        if(!merged) ans.push_back({new_st, new_end});
        return ans;
    }
};
