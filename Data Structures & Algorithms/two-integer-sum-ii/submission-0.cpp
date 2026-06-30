class Solution {
public:
    int bin_src(int l, int r, int t, vector<int>& nums) {
        if(l > r) return 0;
        while(l <= r) {
            int m = l + ((r-l)/2);
            if(nums[m] == t) return m+1;
            else if(nums[m] > t) r = m-1;
            else l = m+1;
        }
        return 0;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            int x = target - nums[i];
            int a = max(bin_src(0, i-1, x, nums), bin_src(i+1, n-1, x, nums));
            if(a > 0) return {min(a,i+1), max(a,i+1)};
        }
        return {0,0};
    }
};
