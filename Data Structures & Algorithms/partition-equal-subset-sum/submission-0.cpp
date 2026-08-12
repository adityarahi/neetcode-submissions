class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        sum /= 2;
        vector<bool> dpPrev(sum + 1,false), dp(sum + 1,false);
        for(int t = 0; t <= sum; t++) {
            if(t == nums[0]) dpPrev[t] = true;
        }
        for(int i = 1; i < n; i++) {
            for(int t = 1; t <= sum; t++) {
                dp[t] = dpPrev[t];
                if(t >= nums[i]) dp[t] = dp[t] || dpPrev[t-nums[i]];
            }
            dpPrev = dp;
        }
        return dp[sum];
    }
};
