class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), curr_reach_idx = 0, max_reach_idx = 0, minJumps = 0;
        if(n == 1) return 0;
        for(int i = 0; i < n; i++) {
            max_reach_idx = max(max_reach_idx, i + nums[i]);
            if(max_reach_idx >= (n-1)) return minJumps + 1;
            if(i == curr_reach_idx) {
                if(max_reach_idx == i) return -1; // cannot reach any further
                minJumps++;
                curr_reach_idx = max_reach_idx;
            }
        }
        return -1;
    }
};
