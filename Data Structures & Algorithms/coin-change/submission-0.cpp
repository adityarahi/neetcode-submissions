class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dpPrev(amount + 1, amount + 1), dp(amount + 1, amount + 1);
        dpPrev[0] = 0;
        for(int j = 1; j <= n; j++) {
            dp[0] = 0;
            for(int i = 1; i <= amount; i++) {
                dp[i] = dpPrev[i]; // option: don't use this coin
                if(i >= coins[j-1]) {
                    dp[i] = min(dp[i], 1 + min(dp[i - coins[j-1]], dpPrev[i - coins[j-1]])); // use this coin
                }
            }
            dpPrev = dp;
        }
        return ((dp[amount] > amount) ? -1 : dp[amount]);  
    }
};
