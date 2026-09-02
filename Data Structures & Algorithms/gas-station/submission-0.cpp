class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g = accumulate(gas.begin(), gas.end(), 0);
        int c = accumulate(cost.begin(), cost.end(), 0);
        if(g < c) return -1;
        int curr_gain = 0, ans = 0;
        for(int i = 0; i < gas.size(); i++) {
            curr_gain += (gas[i] - cost[i]);
            if(curr_gain < 0) {
                curr_gain = 0; // reset gain; this segment does not have starting index
                ans = i+1; // next segment's starting index might be the answer
            }
        }
        return ans;
    }
};
