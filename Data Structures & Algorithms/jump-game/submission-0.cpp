class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach_idx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i > max_reach_idx) return false;
            max_reach_idx = max(max_reach_idx, i + nums[i]);
            if(max_reach_idx >= nums.size()) return true;
        }
        return true;
    }
};
