class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> ans = {nums[0], max(nums[0], nums[1])};
        for(int i = 2; i < n; i++) {
            int tmp = max(ans[1], nums[i] + ans[0]);
            ans[0] = ans[1]; ans[1] = tmp;
        }
        return ans[1];
    }
};
