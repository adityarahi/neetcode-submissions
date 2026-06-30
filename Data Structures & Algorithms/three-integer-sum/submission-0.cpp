class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int t = -nums[i];
            int l = i+1, r = n-1;
            while(l < r) {
                if((nums[l] + nums[r]) > t) r--;
                else if((nums[l] + nums[r]) < t) l++;
                else {
                    int x = nums[l], y = nums[r];
                    while(l < n-1 && nums[l] == nums[l+1]) l++;
                    while(r > 0 && nums[r] == nums[r-1]) r--;
                    ans.push_back({nums[i], x, y});
                    l++;
                    r--;    
                }
            }
        }
        return ans;
    }
};
