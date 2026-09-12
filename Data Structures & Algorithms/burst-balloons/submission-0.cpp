class Solution {
public:
    int find(int l, int r, vector<vector<int>>& dp, vector<int>& v) {
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        dp[l][r] = 0;
        for(int i = l; i <= r; i++) {
            int coins = (v[i]*v[l-1]*v[r+1]);
            dp[l][r] = max(dp[l][r], find(l,i-1,dp,v) + find(i+1,r,dp,v) + coins);
        }
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+2, 1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        for(int i = 1; i <= n; i++) v[i] = nums[i-1];
        return find(1, n, dp, v);
    }
};
